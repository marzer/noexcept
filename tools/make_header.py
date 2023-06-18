#!/usr/bin/env python3
# This file is a part of marzer/noexcept and is subject to the the terms of the MIT license.
# Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
# See https://github.com/marzer/noexcept/blob/master/LICENSE for the full license text.
# SPDX-License-Identifier: MIT

import re
import subprocess
from pathlib import Path
from misk import *
from io import StringIO



RX_AUTOGENERATED_TRAITS = re.compile(r'^[ \t]*//[ \t]*\{\{[ \t]*autogenerated_traits[ \t]*\}\}[ \t]*$', flags=re.MULTILINE)
RX_PERMUTATION_LIST = re.compile(r'^[ \t]*//[ \t]*\{\{[ \t]*permutation_list[ \t]*\}\}[ \t]*$', flags=re.MULTILINE)



def clang_format(s, cwd=None):
	result = subprocess.run(['clang-format', '--style=file'],
		capture_output=True,
		cwd=str(Path.cwd() if cwd is None else cwd),
		encoding='utf-8',
		check=True,
		input=s)
	return str(result.stdout)



def main():
	root_dir = Path(__file__).parent.parent
	template_file = Path(root_dir, 'include/mz/noexcept.hpp.in')
	header_file = Path(root_dir, 'include/mz/noexcept.hpp')

	# generate the base file using muu
	run_python_script(
		Path(root_dir, '../muu/tools/make_single.py'),
		str(template_file)
	)
	text = read_all_text_from_file(header_file)

	# generate all the permutation specializations
	windows = r'defined(_WIN32)'
	amd64 = r'MZ_ARCH_AMD64'
	arm = r'MZ_ARCH_ARM'
	clr = r'defined(__CLR_VER)'
	free_calling_conventions = {
		rf'{windows}' : ( '__cdecl', ),
		rf'{windows} && !{arm}' : ('__vectorcall',  ),
		rf'{windows} && !{amd64}' : ('__stdcall', '__fastcall' ),
		rf'{windows} && {clr}' : ( '__clrcall',  ),
		rf'!{windows}' : ( '', )
	}
	member_calling_conventions = {
		rf'{windows}' : ( '__cdecl', ),
		rf'{windows} && !{arm}' : ('__vectorcall',  ),
		rf'{windows} && !{amd64}' : ('__stdcall', '__fastcall', '__thiscall' ),
		rf'{windows} && {clr}' : ( '__clrcall',  ),
		rf'!{windows}' : ( '', )
	}
	cvref_categories = (
		r'',
		r'&',
		r'&&',
		r'const',
		r'const &',
		r'const &&',
		r'volatile',
		r'volatile &',
		r'volatile &&',
		r'const volatile',
		r'const volatile &',
		r'const volatile &&'
	)
	noexcept_categories = (
		'',
		'noexcept'
	)
	all_permutations = set()
	free_permutations = set()
	member_permutations = set()
	with StringIO() as buf:
		o = lambda s = '', end='\n': print(s, end=end, file=buf)
		def add_permutation(permutation):
			nonlocal all_permutations, free_permutations, member_permutations, o
			all_permutations.add(permutation)
			if permutation.find(r'C::') != -1:
				member_permutations.add(permutation)
			else:
				free_permutations.add(permutation)
			o(rf'MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT({permutation});')

		o(r'// --------- free functions -------------------------------------------------')
		o(r'#if 1')
		o()
		o(r'''#define MZ_SPECIALIZE_ADD_NOEXCEPT(...) \
				template <typename R, typename... P> \
				struct add_noexcept<__VA_ARGS__> \
				{ \
					using type = __VA_ARGS__ noexcept; \
				}

			#define MZ_SPECIALIZE_REMOVE_NOEXCEPT(...) \
				template <typename R, typename... P> \
				struct remove_noexcept<__VA_ARGS__ noexcept> \
				{ \
					using type = __VA_ARGS__; \
				}

			#define MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(...) \
				MZ_SPECIALIZE_ADD_NOEXCEPT(__VA_ARGS__); \
				MZ_SPECIALIZE_REMOVE_NOEXCEPT(__VA_ARGS__)
			
		''')
		for condition, conventions in free_calling_conventions.items():
			o()
			if condition:
				o(rf'#if {condition}')
			for callconv in conventions:
				for varargs in ('',',...'):
					if varargs and callconv not in ('', '__cdecl'):
						continue
					add_permutation(rf'R {callconv}{" " if callconv else ""}(P...{varargs})')
			if condition:
				o(rf'#endif // {condition}')
		o()
		o(r'#endif')
		o()
		o(r'// --------- member functions -------------------------------------------------')
		o(r'#if 1')
		o()
		o(r'''#undef MZ_SPECIALIZE_ADD_NOEXCEPT
			#define MZ_SPECIALIZE_ADD_NOEXCEPT(...) \
				template <typename C, typename R, typename... P> \
				struct add_noexcept<__VA_ARGS__> \
				{ \
					using type = __VA_ARGS__ noexcept; \
				}

			#undef MZ_SPECIALIZE_REMOVE_NOEXCEPT
			#define MZ_SPECIALIZE_REMOVE_NOEXCEPT(...) \
				template <typename C, typename R, typename... P> \
				struct remove_noexcept<__VA_ARGS__ noexcept> \
				{ \
					using type = __VA_ARGS__; \
				}		
		''')
		for condition, conventions in member_calling_conventions.items():
			o()
			if condition:
				o(rf'#if {condition}')
			for callconv in conventions:
				for varargs in ('',',...'):
					if varargs and callconv not in ('', '__cdecl'):
						continue
					for cvref in cvref_categories:
						add_permutation(rf'R ({callconv}{" " if callconv else ""}C::*)(P...{varargs}) {cvref}')
			if condition:
				o(rf'#endif // {condition}')
		o()
		o(r'#endif')

		o(r'''
			#undef MZ_SPECIALIZE_ADD_NOEXCEPT
			#undef MZ_SPECIALIZE_REMOVE_NOEXCEPT
			#undef MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT
		''')
		
		text = RX_AUTOGENERATED_TRAITS.sub(buf.getvalue(), text)

	# add the permutation list
	with StringIO() as buf:
		o = lambda s = '', end='\n': print(s, end=end, file=buf)

		if 1:
			o(r'// all free and member function permutations covered in this file: ')
			free_permutations_sorted = list(free_permutations)
			free_permutations_sorted.sort()
			member_permutations_sorted = list(member_permutations)
			member_permutations_sorted.sort()
			for permutation in free_permutations_sorted:
				o(rf'//    {permutation}')
			for permutation in member_permutations_sorted:
				o(rf'//    {permutation}')
			o(rf'//    {len(all_permutations)} total')

		text = RX_PERMUTATION_LIST.sub(buf.getvalue(), text)

	# clang format
	try:
		text = clang_format(text, cwd=header_file.parent)
	except:
		pass

	print(rf'Writing {header_file}')
	with open(header_file, 'w', newline='\n', encoding=r'utf-8') as f:
		f.write(text)



if __name__ == '__main__':
	main()