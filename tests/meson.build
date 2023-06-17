# This file is a part of marzer/noexcept and is subject to the the terms of the MIT license.
# Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
# See https://github.com/marzer/noexcept/blob/master/LICENSE for the full license text.
# SPDX-License-Identifier: MIT

test_exe = executable(
	'test_exe',
	files('main.cpp'),
	dependencies: [ noexcept_dep ],
	install: false
)

test('test', test_exe)
