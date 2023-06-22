//----------------------------------------------------------------------------------------------------------------------
//
// mz::noexcept
// https://github.com/marzer/noexcept
// SPDX-License-Identifier: MIT
//
//----------------------------------------------------------------------------------------------------------------------
//         THIS FILE WAS ASSEMBLED FROM MULTIPLE HEADER FILES BY A SCRIPT - PLEASE DON'T EDIT IT DIRECTLY
//----------------------------------------------------------------------------------------------------------------------
//
// MIT License
//
// Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
// documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of
// the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//----------------------------------------------------------------------------------------------------------------------
#ifndef MZ_NOEXCEPT_HPP
#define MZ_NOEXCEPT_HPP

#define MZ_NOEXCEPT_VERSION_MAJOR 1
#define MZ_NOEXCEPT_VERSION_MINOR 0
#define MZ_NOEXCEPT_VERSION_PATCH 0

#ifndef MZ_ARCH_AMD64
	#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_AMD64)
		#define MZ_ARCH_AMD64	1
		#define MZ_ARCH_BITNESS 64
	#else
		#define MZ_ARCH_AMD64 0
	#endif
#endif

#ifndef MZ_ARCH_ARM
	#if defined(__aarch64__) || defined(__ARM_ARCH_ISA_A64) || defined(_M_ARM64) || defined(__ARM_64BIT_STATE)         \
		|| defined(_M_ARM64EC)
		#define MZ_ARCH_ARM32	0
		#define MZ_ARCH_ARM64	1
		#define MZ_ARCH_ARM		1
		#define MZ_ARCH_BITNESS 64
	#elif defined(__arm__) || defined(_M_ARM) || defined(__ARM_32BIT_STATE)
		#define MZ_ARCH_ARM32	1
		#define MZ_ARCH_ARM64	0
		#define MZ_ARCH_ARM		1
		#define MZ_ARCH_BITNESS 32
	#else
		#define MZ_ARCH_ARM32 0
		#define MZ_ARCH_ARM64 0
		#define MZ_ARCH_ARM	  0
	#endif
#endif

#include <type_traits>

namespace mz
{
	// --------- base templates -------------------------------------------------

	template <typename T>
	struct add_noexcept
	{
		using type = T;
	};

	template <typename T>
	using add_noexcept_t = typename add_noexcept<T>::type;

	template <typename T>
	struct remove_noexcept
	{
		using type = T;
	};

	template <typename T>
	using remove_noexcept_t = typename remove_noexcept<T>::type;

	template <typename T>
	struct is_noexcept : std::bool_constant<!std::is_same<remove_noexcept_t<T>, T>::value>
	{};

	template <typename T>
	inline constexpr bool is_noexcept_v = is_noexcept<T>::value;

	// --------- cv permutations -------------------------------------------------

	template <typename T>
	struct add_noexcept<const T>
	{
		using type = const typename add_noexcept<T>::type;
	};

	template <typename T>
	struct remove_noexcept<const T>
	{
		using type = const typename remove_noexcept<T>::type;
	};

	template <typename T>
	struct add_noexcept<volatile T>
	{
		using type = volatile typename add_noexcept<T>::type;
	};

	template <typename T>
	struct remove_noexcept<volatile T>
	{
		using type = volatile typename remove_noexcept<T>::type;
	};

	template <typename T>
	struct add_noexcept<const volatile T>
	{
		using type = const volatile typename add_noexcept<T>::type;
	};

	template <typename T>
	struct remove_noexcept<const volatile T>
	{
		using type = const volatile typename remove_noexcept<T>::type;
	};

// --------- free functions -----------------------------------------------------------
#if 1

	#define MZ_SPECIALIZE_ADD_NOEXCEPT(...)                                                                            \
		template <typename R, typename... P>                                                                           \
		struct add_noexcept<__VA_ARGS__>                                                                               \
		{                                                                                                              \
			using type = __VA_ARGS__ noexcept;                                                                         \
		}

	#define MZ_SPECIALIZE_REMOVE_NOEXCEPT(...)                                                                         \
		template <typename R, typename... P>                                                                           \
		struct remove_noexcept<__VA_ARGS__ noexcept>                                                                   \
		{                                                                                                              \
			using type = __VA_ARGS__;                                                                                  \
		}

	#define MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(...)                                                                     \
		MZ_SPECIALIZE_ADD_NOEXCEPT(__VA_ARGS__);                                                                       \
		MZ_SPECIALIZE_REMOVE_NOEXCEPT(__VA_ARGS__)

	#if !defined(_WIN32)
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R(P...));
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R(P..., ...));
	#endif // !defined(_WIN32)

	#if defined(_WIN32)
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R __cdecl(P...));
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R __cdecl(P..., ...));
	#endif // defined(_WIN32)

	#if defined(_WIN32) && !MZ_ARCH_ARM
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R __vectorcall(P...));
	#endif // defined(_WIN32) && !MZ_ARCH_ARM

	#if defined(_WIN32) && !MZ_ARCH_AMD64
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R __stdcall(P...));
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R __fastcall(P...));
	#endif // defined(_WIN32) && !MZ_ARCH_AMD64

	#if defined(_WIN32) && defined(__CLR_VER)
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R __clrcall(P...));
	#endif // defined(_WIN32) && defined(__CLR_VER)

#endif

// --------- member function pointers -------------------------------------------------
#if 1

	#undef MZ_SPECIALIZE_ADD_NOEXCEPT
	#define MZ_SPECIALIZE_ADD_NOEXCEPT(...)                                                                            \
		template <typename C, typename R, typename... P>                                                               \
		struct add_noexcept<__VA_ARGS__>                                                                               \
		{                                                                                                              \
			using type = __VA_ARGS__ noexcept;                                                                         \
		}

	#undef MZ_SPECIALIZE_REMOVE_NOEXCEPT
	#define MZ_SPECIALIZE_REMOVE_NOEXCEPT(...)                                                                         \
		template <typename C, typename R, typename... P>                                                               \
		struct remove_noexcept<__VA_ARGS__ noexcept>                                                                   \
		{                                                                                                              \
			using type = __VA_ARGS__;                                                                                  \
		}

	#if !defined(_WIN32)
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P...));
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P...) &);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P...) &&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P...) const);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P...) const&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P...) const&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P...) volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P...) volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P...) volatile&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P...) const volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P...) const volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P...) const volatile&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P..., ...));
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P..., ...) &);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P..., ...) &&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P..., ...) const);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P..., ...) const&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P..., ...) const&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P..., ...) volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P..., ...) volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P..., ...) volatile&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P..., ...) const volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P..., ...) const volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (C::*)(P..., ...) const volatile&&);
	#endif // !defined(_WIN32)

	#if defined(_WIN32)
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P...));
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P...) &);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P...) &&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P...) const);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P...) const&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P...) const&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P...) volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P...) volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P...) volatile&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P...) const volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P...) const volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P...) const volatile&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P..., ...));
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P..., ...) &);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P..., ...) &&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P..., ...) const);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P..., ...) const&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P..., ...) const&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P..., ...) volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P..., ...) volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P..., ...) volatile&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P..., ...) const volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P..., ...) const volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__cdecl C::*)(P..., ...) const volatile&&);
	#endif // defined(_WIN32)

	#if defined(_WIN32) && !MZ_ARCH_ARM
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__vectorcall C::*)(P...));
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__vectorcall C::*)(P...) &);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__vectorcall C::*)(P...) &&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__vectorcall C::*)(P...) const);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__vectorcall C::*)(P...) const&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__vectorcall C::*)(P...) const&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__vectorcall C::*)(P...) volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__vectorcall C::*)(P...) volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__vectorcall C::*)(P...) volatile&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__vectorcall C::*)(P...) const volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__vectorcall C::*)(P...) const volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__vectorcall C::*)(P...) const volatile&&);
	#endif // defined(_WIN32) && !MZ_ARCH_ARM

	#if defined(_WIN32) && !MZ_ARCH_AMD64
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__stdcall C::*)(P...));
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__stdcall C::*)(P...) &);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__stdcall C::*)(P...) &&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__stdcall C::*)(P...) const);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__stdcall C::*)(P...) const&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__stdcall C::*)(P...) const&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__stdcall C::*)(P...) volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__stdcall C::*)(P...) volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__stdcall C::*)(P...) volatile&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__stdcall C::*)(P...) const volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__stdcall C::*)(P...) const volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__stdcall C::*)(P...) const volatile&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__fastcall C::*)(P...));
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__fastcall C::*)(P...) &);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__fastcall C::*)(P...) &&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__fastcall C::*)(P...) const);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__fastcall C::*)(P...) const&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__fastcall C::*)(P...) const&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__fastcall C::*)(P...) volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__fastcall C::*)(P...) volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__fastcall C::*)(P...) volatile&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__fastcall C::*)(P...) const volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__fastcall C::*)(P...) const volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__fastcall C::*)(P...) const volatile&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__thiscall C::*)(P...));
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__thiscall C::*)(P...) &);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__thiscall C::*)(P...) &&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__thiscall C::*)(P...) const);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__thiscall C::*)(P...) const&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__thiscall C::*)(P...) const&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__thiscall C::*)(P...) volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__thiscall C::*)(P...) volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__thiscall C::*)(P...) volatile&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__thiscall C::*)(P...) const volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__thiscall C::*)(P...) const volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__thiscall C::*)(P...) const volatile&&);
	#endif // defined(_WIN32) && !MZ_ARCH_AMD64

	#if defined(_WIN32) && defined(__CLR_VER)
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__clrcall C::*)(P...));
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__clrcall C::*)(P...) &);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__clrcall C::*)(P...) &&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__clrcall C::*)(P...) const);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__clrcall C::*)(P...) const&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__clrcall C::*)(P...) const&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__clrcall C::*)(P...) volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__clrcall C::*)(P...) volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__clrcall C::*)(P...) volatile&&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__clrcall C::*)(P...) const volatile);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__clrcall C::*)(P...) const volatile&);
	MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT(R (__clrcall C::*)(P...) const volatile&&);
	#endif // defined(_WIN32) && defined(__CLR_VER)

#endif

#undef MZ_SPECIALIZE_ADD_NOEXCEPT
#undef MZ_SPECIALIZE_REMOVE_NOEXCEPT
#undef MZ_SPECIALIZE_ADD_REMOVE_NOEXCEPT

}

// all free and member function permutations covered in this file:
//    R (P...)
//    R (P..., ...)
//    R __cdecl(P...)
//    R __cdecl(P..., ...)
//    R __clrcall(P...)
//    R __fastcall(P...)
//    R __stdcall(P...)
//    R __vectorcall(P...)
//    R (C::*)(P...)
//    R (C::*)(P...) &
//    R (C::*)(P...) &&
//    R (C::*)(P...) const
//    R (C::*)(P...) const &
//    R (C::*)(P...) const &&
//    R (C::*)(P...) const volatile
//    R (C::*)(P...) const volatile &
//    R (C::*)(P...) const volatile &&
//    R (C::*)(P...) volatile
//    R (C::*)(P...) volatile &
//    R (C::*)(P...) volatile &&
//    R (C::*)(P..., ...)
//    R (C::*)(P..., ...) &
//    R (C::*)(P..., ...) &&
//    R (C::*)(P..., ...) const
//    R (C::*)(P..., ...) const &
//    R (C::*)(P..., ...) const &&
//    R (C::*)(P..., ...) const volatile
//    R (C::*)(P..., ...) const volatile &
//    R (C::*)(P..., ...) const volatile &&
//    R (C::*)(P..., ...) volatile
//    R (C::*)(P..., ...) volatile &
//    R (C::*)(P..., ...) volatile &&
//    R (__cdecl C::*)(P...)
//    R (__cdecl C::*)(P...) &
//    R (__cdecl C::*)(P...) &&
//    R (__cdecl C::*)(P...) const
//    R (__cdecl C::*)(P...) const &
//    R (__cdecl C::*)(P...) const &&
//    R (__cdecl C::*)(P...) const volatile
//    R (__cdecl C::*)(P...) const volatile &
//    R (__cdecl C::*)(P...) const volatile &&
//    R (__cdecl C::*)(P...) volatile
//    R (__cdecl C::*)(P...) volatile &
//    R (__cdecl C::*)(P...) volatile &&
//    R (__cdecl C::*)(P..., ...)
//    R (__cdecl C::*)(P..., ...) &
//    R (__cdecl C::*)(P..., ...) &&
//    R (__cdecl C::*)(P..., ...) const
//    R (__cdecl C::*)(P..., ...) const &
//    R (__cdecl C::*)(P..., ...) const &&
//    R (__cdecl C::*)(P..., ...) const volatile
//    R (__cdecl C::*)(P..., ...) const volatile &
//    R (__cdecl C::*)(P..., ...) const volatile &&
//    R (__cdecl C::*)(P..., ...) volatile
//    R (__cdecl C::*)(P..., ...) volatile &
//    R (__cdecl C::*)(P..., ...) volatile &&
//    R (__clrcall C::*)(P...)
//    R (__clrcall C::*)(P...) &
//    R (__clrcall C::*)(P...) &&
//    R (__clrcall C::*)(P...) const
//    R (__clrcall C::*)(P...) const &
//    R (__clrcall C::*)(P...) const &&
//    R (__clrcall C::*)(P...) const volatile
//    R (__clrcall C::*)(P...) const volatile &
//    R (__clrcall C::*)(P...) const volatile &&
//    R (__clrcall C::*)(P...) volatile
//    R (__clrcall C::*)(P...) volatile &
//    R (__clrcall C::*)(P...) volatile &&
//    R (__fastcall C::*)(P...)
//    R (__fastcall C::*)(P...) &
//    R (__fastcall C::*)(P...) &&
//    R (__fastcall C::*)(P...) const
//    R (__fastcall C::*)(P...) const &
//    R (__fastcall C::*)(P...) const &&
//    R (__fastcall C::*)(P...) const volatile
//    R (__fastcall C::*)(P...) const volatile &
//    R (__fastcall C::*)(P...) const volatile &&
//    R (__fastcall C::*)(P...) volatile
//    R (__fastcall C::*)(P...) volatile &
//    R (__fastcall C::*)(P...) volatile &&
//    R (__stdcall C::*)(P...)
//    R (__stdcall C::*)(P...) &
//    R (__stdcall C::*)(P...) &&
//    R (__stdcall C::*)(P...) const
//    R (__stdcall C::*)(P...) const &
//    R (__stdcall C::*)(P...) const &&
//    R (__stdcall C::*)(P...) const volatile
//    R (__stdcall C::*)(P...) const volatile &
//    R (__stdcall C::*)(P...) const volatile &&
//    R (__stdcall C::*)(P...) volatile
//    R (__stdcall C::*)(P...) volatile &
//    R (__stdcall C::*)(P...) volatile &&
//    R (__thiscall C::*)(P...)
//    R (__thiscall C::*)(P...) &
//    R (__thiscall C::*)(P...) &&
//    R (__thiscall C::*)(P...) const
//    R (__thiscall C::*)(P...) const &
//    R (__thiscall C::*)(P...) const &&
//    R (__thiscall C::*)(P...) const volatile
//    R (__thiscall C::*)(P...) const volatile &
//    R (__thiscall C::*)(P...) const volatile &&
//    R (__thiscall C::*)(P...) volatile
//    R (__thiscall C::*)(P...) volatile &
//    R (__thiscall C::*)(P...) volatile &&
//    R (__vectorcall C::*)(P...)
//    R (__vectorcall C::*)(P...) &
//    R (__vectorcall C::*)(P...) &&
//    R (__vectorcall C::*)(P...) const
//    R (__vectorcall C::*)(P...) const &
//    R (__vectorcall C::*)(P...) const &&
//    R (__vectorcall C::*)(P...) const volatile
//    R (__vectorcall C::*)(P...) const volatile &
//    R (__vectorcall C::*)(P...) const volatile &&
//    R (__vectorcall C::*)(P...) volatile
//    R (__vectorcall C::*)(P...) volatile &
//    R (__vectorcall C::*)(P...) volatile &&
//    116 total

#endif // MZ_NOEXCEPT_HPP
