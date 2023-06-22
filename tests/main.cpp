// This file is a part of marzer/noexcept and is subject to the the terms of the MIT license.
// Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
// See https://github.com/marzer/noexcept/blob/master/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

#include <mz/noexcept.hpp>
#include <type_traits>

#define check_same(a, b) static_assert(std::is_same_v<a, b>)

// --------- free functions -----------------------------------------------------------

// void (int)
namespace ns_0
{
	using func			= void(int);
	using func_noexcept = void(int) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (int, ...)
namespace ns_1
{
	using func			= void(int, ...);
	using func_noexcept = void(int, ...) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

#if defined(_WIN32)

// void __cdecl(int)
namespace ns_2
{
	using func			= void __cdecl(int);
	using func_noexcept = void __cdecl(int) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void __cdecl(int, ...)
namespace ns_3
{
	using func			= void __cdecl(int, ...);
	using func_noexcept = void __cdecl(int, ...) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

#endif // defined(_WIN32)

#if defined(_WIN32) && !MZ_ARCH_ARM

// void __vectorcall(int)
namespace ns_4
{
	using func			= void __vectorcall(int);
	using func_noexcept = void __vectorcall(int) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

#endif // defined(_WIN32) && !MZ_ARCH_ARM

#if defined(_WIN32) && !MZ_ARCH_AMD64

// void __stdcall(int)
namespace ns_5
{
	using func			= void __stdcall(int);
	using func_noexcept = void __stdcall(int) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void __fastcall(int)
namespace ns_6
{
	using func			= void __fastcall(int);
	using func_noexcept = void __fastcall(int) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

#endif // defined(_WIN32) && !MZ_ARCH_AMD64

#if defined(_WIN32) && defined(__CLR_VER)

// void __clrcall(int)
namespace ns_7
{
	using func			= void __clrcall(int);
	using func_noexcept = void __clrcall(int) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

#endif // defined(_WIN32) && defined(__CLR_VER)

// --------- member function pointers -------------------------------------------------

struct dummy
{};

// void (dummy::*)(int)
namespace ns_8
{
	using func			= void (dummy::*)(int);
	using func_noexcept = void (dummy::*)(int) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int) &
namespace ns_9
{
	using func			= void (dummy::*)(int) &;
	using func_noexcept = void (dummy::*)(int) & noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int) &&
namespace ns_10
{
	using func			= void (dummy::*)(int) &&;
	using func_noexcept = void (dummy::*)(int) && noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int) const
namespace ns_11
{
	using func			= void (dummy::*)(int) const;
	using func_noexcept = void (dummy::*)(int) const noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int) const &
namespace ns_12
{
	using func			= void (dummy::*)(int) const&;
	using func_noexcept = void (dummy::*)(int) const& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int) const &&
namespace ns_13
{
	using func			= void (dummy::*)(int) const&&;
	using func_noexcept = void (dummy::*)(int) const&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int) volatile
namespace ns_14
{
	using func			= void (dummy::*)(int) volatile;
	using func_noexcept = void (dummy::*)(int) volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int) volatile &
namespace ns_15
{
	using func			= void (dummy::*)(int) volatile&;
	using func_noexcept = void (dummy::*)(int) volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int) volatile &&
namespace ns_16
{
	using func			= void (dummy::*)(int) volatile&&;
	using func_noexcept = void (dummy::*)(int) volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int) const volatile
namespace ns_17
{
	using func			= void (dummy::*)(int) const volatile;
	using func_noexcept = void (dummy::*)(int) const volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int) const volatile &
namespace ns_18
{
	using func			= void (dummy::*)(int) const volatile&;
	using func_noexcept = void (dummy::*)(int) const volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int) const volatile &&
namespace ns_19
{
	using func			= void (dummy::*)(int) const volatile&&;
	using func_noexcept = void (dummy::*)(int) const volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int, ...)
namespace ns_20
{
	using func			= void (dummy::*)(int, ...);
	using func_noexcept = void (dummy::*)(int, ...) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int, ...) &
namespace ns_21
{
	using func			= void (dummy::*)(int, ...) &;
	using func_noexcept = void (dummy::*)(int, ...) & noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int, ...) &&
namespace ns_22
{
	using func			= void (dummy::*)(int, ...) &&;
	using func_noexcept = void (dummy::*)(int, ...) && noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int, ...) const
namespace ns_23
{
	using func			= void (dummy::*)(int, ...) const;
	using func_noexcept = void (dummy::*)(int, ...) const noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int, ...) const &
namespace ns_24
{
	using func			= void (dummy::*)(int, ...) const&;
	using func_noexcept = void (dummy::*)(int, ...) const& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int, ...) const &&
namespace ns_25
{
	using func			= void (dummy::*)(int, ...) const&&;
	using func_noexcept = void (dummy::*)(int, ...) const&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int, ...) volatile
namespace ns_26
{
	using func			= void (dummy::*)(int, ...) volatile;
	using func_noexcept = void (dummy::*)(int, ...) volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int, ...) volatile &
namespace ns_27
{
	using func			= void (dummy::*)(int, ...) volatile&;
	using func_noexcept = void (dummy::*)(int, ...) volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int, ...) volatile &&
namespace ns_28
{
	using func			= void (dummy::*)(int, ...) volatile&&;
	using func_noexcept = void (dummy::*)(int, ...) volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int, ...) const volatile
namespace ns_29
{
	using func			= void (dummy::*)(int, ...) const volatile;
	using func_noexcept = void (dummy::*)(int, ...) const volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int, ...) const volatile &
namespace ns_30
{
	using func			= void (dummy::*)(int, ...) const volatile&;
	using func_noexcept = void (dummy::*)(int, ...) const volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (dummy::*)(int, ...) const volatile &&
namespace ns_31
{
	using func			= void (dummy::*)(int, ...) const volatile&&;
	using func_noexcept = void (dummy::*)(int, ...) const volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

#if defined(_WIN32)

// void (__cdecl dummy::*)(int)
namespace ns_32
{
	using func			= void (__cdecl dummy::*)(int);
	using func_noexcept = void (__cdecl dummy::*)(int) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int) &
namespace ns_33
{
	using func			= void (__cdecl dummy::*)(int) &;
	using func_noexcept = void (__cdecl dummy::*)(int) & noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int) &&
namespace ns_34
{
	using func			= void (__cdecl dummy::*)(int) &&;
	using func_noexcept = void (__cdecl dummy::*)(int) && noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int) const
namespace ns_35
{
	using func			= void (__cdecl dummy::*)(int) const;
	using func_noexcept = void (__cdecl dummy::*)(int) const noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int) const &
namespace ns_36
{
	using func			= void (__cdecl dummy::*)(int) const&;
	using func_noexcept = void (__cdecl dummy::*)(int) const& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int) const &&
namespace ns_37
{
	using func			= void (__cdecl dummy::*)(int) const&&;
	using func_noexcept = void (__cdecl dummy::*)(int) const&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int) volatile
namespace ns_38
{
	using func			= void (__cdecl dummy::*)(int) volatile;
	using func_noexcept = void (__cdecl dummy::*)(int) volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int) volatile &
namespace ns_39
{
	using func			= void (__cdecl dummy::*)(int) volatile&;
	using func_noexcept = void (__cdecl dummy::*)(int) volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int) volatile &&
namespace ns_40
{
	using func			= void (__cdecl dummy::*)(int) volatile&&;
	using func_noexcept = void (__cdecl dummy::*)(int) volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int) const volatile
namespace ns_41
{
	using func			= void (__cdecl dummy::*)(int) const volatile;
	using func_noexcept = void (__cdecl dummy::*)(int) const volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int) const volatile &
namespace ns_42
{
	using func			= void (__cdecl dummy::*)(int) const volatile&;
	using func_noexcept = void (__cdecl dummy::*)(int) const volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int) const volatile &&
namespace ns_43
{
	using func			= void (__cdecl dummy::*)(int) const volatile&&;
	using func_noexcept = void (__cdecl dummy::*)(int) const volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int, ...)
namespace ns_44
{
	using func			= void (__cdecl dummy::*)(int, ...);
	using func_noexcept = void (__cdecl dummy::*)(int, ...) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int, ...) &
namespace ns_45
{
	using func			= void (__cdecl dummy::*)(int, ...) &;
	using func_noexcept = void (__cdecl dummy::*)(int, ...) & noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int, ...) &&
namespace ns_46
{
	using func			= void (__cdecl dummy::*)(int, ...) &&;
	using func_noexcept = void (__cdecl dummy::*)(int, ...) && noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int, ...) const
namespace ns_47
{
	using func			= void (__cdecl dummy::*)(int, ...) const;
	using func_noexcept = void (__cdecl dummy::*)(int, ...) const noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int, ...) const &
namespace ns_48
{
	using func			= void (__cdecl dummy::*)(int, ...) const&;
	using func_noexcept = void (__cdecl dummy::*)(int, ...) const& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int, ...) const &&
namespace ns_49
{
	using func			= void (__cdecl dummy::*)(int, ...) const&&;
	using func_noexcept = void (__cdecl dummy::*)(int, ...) const&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int, ...) volatile
namespace ns_50
{
	using func			= void (__cdecl dummy::*)(int, ...) volatile;
	using func_noexcept = void (__cdecl dummy::*)(int, ...) volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int, ...) volatile &
namespace ns_51
{
	using func			= void (__cdecl dummy::*)(int, ...) volatile&;
	using func_noexcept = void (__cdecl dummy::*)(int, ...) volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int, ...) volatile &&
namespace ns_52
{
	using func			= void (__cdecl dummy::*)(int, ...) volatile&&;
	using func_noexcept = void (__cdecl dummy::*)(int, ...) volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int, ...) const volatile
namespace ns_53
{
	using func			= void (__cdecl dummy::*)(int, ...) const volatile;
	using func_noexcept = void (__cdecl dummy::*)(int, ...) const volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int, ...) const volatile &
namespace ns_54
{
	using func			= void (__cdecl dummy::*)(int, ...) const volatile&;
	using func_noexcept = void (__cdecl dummy::*)(int, ...) const volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__cdecl dummy::*)(int, ...) const volatile &&
namespace ns_55
{
	using func			= void (__cdecl dummy::*)(int, ...) const volatile&&;
	using func_noexcept = void (__cdecl dummy::*)(int, ...) const volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

#endif // defined(_WIN32)

#if defined(_WIN32) && !MZ_ARCH_ARM

// void (__vectorcall dummy::*)(int)
namespace ns_56
{
	using func			= void (__vectorcall dummy::*)(int);
	using func_noexcept = void (__vectorcall dummy::*)(int) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__vectorcall dummy::*)(int) &
namespace ns_57
{
	using func			= void (__vectorcall dummy::*)(int) &;
	using func_noexcept = void (__vectorcall dummy::*)(int) & noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__vectorcall dummy::*)(int) &&
namespace ns_58
{
	using func			= void (__vectorcall dummy::*)(int) &&;
	using func_noexcept = void (__vectorcall dummy::*)(int) && noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__vectorcall dummy::*)(int) const
namespace ns_59
{
	using func			= void (__vectorcall dummy::*)(int) const;
	using func_noexcept = void (__vectorcall dummy::*)(int) const noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__vectorcall dummy::*)(int) const &
namespace ns_60
{
	using func			= void (__vectorcall dummy::*)(int) const&;
	using func_noexcept = void (__vectorcall dummy::*)(int) const& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__vectorcall dummy::*)(int) const &&
namespace ns_61
{
	using func			= void (__vectorcall dummy::*)(int) const&&;
	using func_noexcept = void (__vectorcall dummy::*)(int) const&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__vectorcall dummy::*)(int) volatile
namespace ns_62
{
	using func			= void (__vectorcall dummy::*)(int) volatile;
	using func_noexcept = void (__vectorcall dummy::*)(int) volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__vectorcall dummy::*)(int) volatile &
namespace ns_63
{
	using func			= void (__vectorcall dummy::*)(int) volatile&;
	using func_noexcept = void (__vectorcall dummy::*)(int) volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__vectorcall dummy::*)(int) volatile &&
namespace ns_64
{
	using func			= void (__vectorcall dummy::*)(int) volatile&&;
	using func_noexcept = void (__vectorcall dummy::*)(int) volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__vectorcall dummy::*)(int) const volatile
namespace ns_65
{
	using func			= void (__vectorcall dummy::*)(int) const volatile;
	using func_noexcept = void (__vectorcall dummy::*)(int) const volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__vectorcall dummy::*)(int) const volatile &
namespace ns_66
{
	using func			= void (__vectorcall dummy::*)(int) const volatile&;
	using func_noexcept = void (__vectorcall dummy::*)(int) const volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__vectorcall dummy::*)(int) const volatile &&
namespace ns_67
{
	using func			= void (__vectorcall dummy::*)(int) const volatile&&;
	using func_noexcept = void (__vectorcall dummy::*)(int) const volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

#endif // defined(_WIN32) && !MZ_ARCH_ARM

#if defined(_WIN32) && !MZ_ARCH_AMD64

// void (__stdcall dummy::*)(int)
namespace ns_68
{
	using func			= void (__stdcall dummy::*)(int);
	using func_noexcept = void (__stdcall dummy::*)(int) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__stdcall dummy::*)(int) &
namespace ns_69
{
	using func			= void (__stdcall dummy::*)(int) &;
	using func_noexcept = void (__stdcall dummy::*)(int) & noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__stdcall dummy::*)(int) &&
namespace ns_70
{
	using func			= void (__stdcall dummy::*)(int) &&;
	using func_noexcept = void (__stdcall dummy::*)(int) && noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__stdcall dummy::*)(int) const
namespace ns_71
{
	using func			= void (__stdcall dummy::*)(int) const;
	using func_noexcept = void (__stdcall dummy::*)(int) const noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__stdcall dummy::*)(int) const &
namespace ns_72
{
	using func			= void (__stdcall dummy::*)(int) const&;
	using func_noexcept = void (__stdcall dummy::*)(int) const& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__stdcall dummy::*)(int) const &&
namespace ns_73
{
	using func			= void (__stdcall dummy::*)(int) const&&;
	using func_noexcept = void (__stdcall dummy::*)(int) const&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__stdcall dummy::*)(int) volatile
namespace ns_74
{
	using func			= void (__stdcall dummy::*)(int) volatile;
	using func_noexcept = void (__stdcall dummy::*)(int) volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__stdcall dummy::*)(int) volatile &
namespace ns_75
{
	using func			= void (__stdcall dummy::*)(int) volatile&;
	using func_noexcept = void (__stdcall dummy::*)(int) volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__stdcall dummy::*)(int) volatile &&
namespace ns_76
{
	using func			= void (__stdcall dummy::*)(int) volatile&&;
	using func_noexcept = void (__stdcall dummy::*)(int) volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__stdcall dummy::*)(int) const volatile
namespace ns_77
{
	using func			= void (__stdcall dummy::*)(int) const volatile;
	using func_noexcept = void (__stdcall dummy::*)(int) const volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__stdcall dummy::*)(int) const volatile &
namespace ns_78
{
	using func			= void (__stdcall dummy::*)(int) const volatile&;
	using func_noexcept = void (__stdcall dummy::*)(int) const volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__stdcall dummy::*)(int) const volatile &&
namespace ns_79
{
	using func			= void (__stdcall dummy::*)(int) const volatile&&;
	using func_noexcept = void (__stdcall dummy::*)(int) const volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__fastcall dummy::*)(int)
namespace ns_80
{
	using func			= void (__fastcall dummy::*)(int);
	using func_noexcept = void (__fastcall dummy::*)(int) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__fastcall dummy::*)(int) &
namespace ns_81
{
	using func			= void (__fastcall dummy::*)(int) &;
	using func_noexcept = void (__fastcall dummy::*)(int) & noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__fastcall dummy::*)(int) &&
namespace ns_82
{
	using func			= void (__fastcall dummy::*)(int) &&;
	using func_noexcept = void (__fastcall dummy::*)(int) && noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__fastcall dummy::*)(int) const
namespace ns_83
{
	using func			= void (__fastcall dummy::*)(int) const;
	using func_noexcept = void (__fastcall dummy::*)(int) const noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__fastcall dummy::*)(int) const &
namespace ns_84
{
	using func			= void (__fastcall dummy::*)(int) const&;
	using func_noexcept = void (__fastcall dummy::*)(int) const& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__fastcall dummy::*)(int) const &&
namespace ns_85
{
	using func			= void (__fastcall dummy::*)(int) const&&;
	using func_noexcept = void (__fastcall dummy::*)(int) const&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__fastcall dummy::*)(int) volatile
namespace ns_86
{
	using func			= void (__fastcall dummy::*)(int) volatile;
	using func_noexcept = void (__fastcall dummy::*)(int) volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__fastcall dummy::*)(int) volatile &
namespace ns_87
{
	using func			= void (__fastcall dummy::*)(int) volatile&;
	using func_noexcept = void (__fastcall dummy::*)(int) volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__fastcall dummy::*)(int) volatile &&
namespace ns_88
{
	using func			= void (__fastcall dummy::*)(int) volatile&&;
	using func_noexcept = void (__fastcall dummy::*)(int) volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__fastcall dummy::*)(int) const volatile
namespace ns_89
{
	using func			= void (__fastcall dummy::*)(int) const volatile;
	using func_noexcept = void (__fastcall dummy::*)(int) const volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__fastcall dummy::*)(int) const volatile &
namespace ns_90
{
	using func			= void (__fastcall dummy::*)(int) const volatile&;
	using func_noexcept = void (__fastcall dummy::*)(int) const volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__fastcall dummy::*)(int) const volatile &&
namespace ns_91
{
	using func			= void (__fastcall dummy::*)(int) const volatile&&;
	using func_noexcept = void (__fastcall dummy::*)(int) const volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__thiscall dummy::*)(int)
namespace ns_92
{
	using func			= void (__thiscall dummy::*)(int);
	using func_noexcept = void (__thiscall dummy::*)(int) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__thiscall dummy::*)(int) &
namespace ns_93
{
	using func			= void (__thiscall dummy::*)(int) &;
	using func_noexcept = void (__thiscall dummy::*)(int) & noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__thiscall dummy::*)(int) &&
namespace ns_94
{
	using func			= void (__thiscall dummy::*)(int) &&;
	using func_noexcept = void (__thiscall dummy::*)(int) && noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__thiscall dummy::*)(int) const
namespace ns_95
{
	using func			= void (__thiscall dummy::*)(int) const;
	using func_noexcept = void (__thiscall dummy::*)(int) const noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__thiscall dummy::*)(int) const &
namespace ns_96
{
	using func			= void (__thiscall dummy::*)(int) const&;
	using func_noexcept = void (__thiscall dummy::*)(int) const& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__thiscall dummy::*)(int) const &&
namespace ns_97
{
	using func			= void (__thiscall dummy::*)(int) const&&;
	using func_noexcept = void (__thiscall dummy::*)(int) const&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__thiscall dummy::*)(int) volatile
namespace ns_98
{
	using func			= void (__thiscall dummy::*)(int) volatile;
	using func_noexcept = void (__thiscall dummy::*)(int) volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__thiscall dummy::*)(int) volatile &
namespace ns_99
{
	using func			= void (__thiscall dummy::*)(int) volatile&;
	using func_noexcept = void (__thiscall dummy::*)(int) volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__thiscall dummy::*)(int) volatile &&
namespace ns_100
{
	using func			= void (__thiscall dummy::*)(int) volatile&&;
	using func_noexcept = void (__thiscall dummy::*)(int) volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__thiscall dummy::*)(int) const volatile
namespace ns_101
{
	using func			= void (__thiscall dummy::*)(int) const volatile;
	using func_noexcept = void (__thiscall dummy::*)(int) const volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__thiscall dummy::*)(int) const volatile &
namespace ns_102
{
	using func			= void (__thiscall dummy::*)(int) const volatile&;
	using func_noexcept = void (__thiscall dummy::*)(int) const volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__thiscall dummy::*)(int) const volatile &&
namespace ns_103
{
	using func			= void (__thiscall dummy::*)(int) const volatile&&;
	using func_noexcept = void (__thiscall dummy::*)(int) const volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

#endif // defined(_WIN32) && !MZ_ARCH_AMD64

#if defined(_WIN32) && defined(__CLR_VER)

// void (__clrcall dummy::*)(int)
namespace ns_104
{
	using func			= void (__clrcall dummy::*)(int);
	using func_noexcept = void (__clrcall dummy::*)(int) noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__clrcall dummy::*)(int) &
namespace ns_105
{
	using func			= void (__clrcall dummy::*)(int) &;
	using func_noexcept = void (__clrcall dummy::*)(int) & noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__clrcall dummy::*)(int) &&
namespace ns_106
{
	using func			= void (__clrcall dummy::*)(int) &&;
	using func_noexcept = void (__clrcall dummy::*)(int) && noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__clrcall dummy::*)(int) const
namespace ns_107
{
	using func			= void (__clrcall dummy::*)(int) const;
	using func_noexcept = void (__clrcall dummy::*)(int) const noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__clrcall dummy::*)(int) const &
namespace ns_108
{
	using func			= void (__clrcall dummy::*)(int) const&;
	using func_noexcept = void (__clrcall dummy::*)(int) const& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__clrcall dummy::*)(int) const &&
namespace ns_109
{
	using func			= void (__clrcall dummy::*)(int) const&&;
	using func_noexcept = void (__clrcall dummy::*)(int) const&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__clrcall dummy::*)(int) volatile
namespace ns_110
{
	using func			= void (__clrcall dummy::*)(int) volatile;
	using func_noexcept = void (__clrcall dummy::*)(int) volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__clrcall dummy::*)(int) volatile &
namespace ns_111
{
	using func			= void (__clrcall dummy::*)(int) volatile&;
	using func_noexcept = void (__clrcall dummy::*)(int) volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__clrcall dummy::*)(int) volatile &&
namespace ns_112
{
	using func			= void (__clrcall dummy::*)(int) volatile&&;
	using func_noexcept = void (__clrcall dummy::*)(int) volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__clrcall dummy::*)(int) const volatile
namespace ns_113
{
	using func			= void (__clrcall dummy::*)(int) const volatile;
	using func_noexcept = void (__clrcall dummy::*)(int) const volatile noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__clrcall dummy::*)(int) const volatile &
namespace ns_114
{
	using func			= void (__clrcall dummy::*)(int) const volatile&;
	using func_noexcept = void (__clrcall dummy::*)(int) const volatile& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

// void (__clrcall dummy::*)(int) const volatile &&
namespace ns_115
{
	using func			= void (__clrcall dummy::*)(int) const volatile&&;
	using func_noexcept = void (__clrcall dummy::*)(int) const volatile&& noexcept;
	check_same(mz::add_noexcept_t<func>, func_noexcept);
	check_same(mz::add_noexcept_t<func_noexcept>, func_noexcept);
	check_same(mz::remove_noexcept_t<func>, func);
	check_same(mz::remove_noexcept_t<func_noexcept>, func);
	static_assert(!mz::is_noexcept_v<func>);
	static_assert(mz::is_noexcept_v<func_noexcept>);
}

#endif // defined(_WIN32) && defined(__CLR_VER)

int main()
{
	return 0;
}
