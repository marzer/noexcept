# `mz::noexcept` [![MIT license](docs/images/badge-license-MIT.svg)](./LICENSE) [![C++17](docs/images/badge-C++17.svg)][cpp_compilers] [![Sponsor](docs/images/badge-sponsor.svg)][sponsor] [![Gitter](docs/images/badge-gitter.svg)][gitter]

Traits for manipulating `noexcept` in C++'s type system.

Requires C++17.

<br>

## Synopsis

```cpp
namespace mz
{
	// has member 'type' as T with the `noexcept` specifier added
	//
	// ::type will simply be T if T is not a function or
	// (possibly cv-qualified) member function pointer type.
	template <typename T>
	struct add_noexcept;

	// type alias for directly unpacking add_noexcept
	// (in the same vein as std::add_const / std::add_const_t, etc.)
	template <typename T>
	using add_noexcept_t = typename add_noexcept<T>::type;

	// has member 'type' as T with the `noexcept` specifier removed
	//
	// ::type will simply be T if T is not a function or
	// (possibly cv-qualified) member function pointer type.
	template <typename T>
	struct remove_noexcept;

	// type alias for directly unpacking remove_noexcept
	// (in the same vein as std::remove_const / std::remove_const_t, etc.)
	template <typename T>
	using remove_noexcept_t = typename remove_noexcept<T>::type;

	// has member 'value' indicating if T was a function
	// or member function pointer type with the noexcept specifier present.
	template <typename T>
	struct is_noexcept;

	// variable template containing the value of is_noexcept
	// (in the same vein as std::is_const / std::is_const_v, etc.)
	template <typename T>
	inline constexpr bool is_noexcept_v = is_noexcept<T>::value;
}
```

<br>

## Usage

The library is a single header so the easiest way to use it is to drop [noexcept.hpp] somewhere in your project.

Alternatively you can add `include` to your include paths then `#include <mz/noexcept.hpp>`

There is also support for use as a `meson.build` subproject.

<br>

## License

MIT. See [LICENSE](LICENSE).

<br>

## Contributing

There are three ways you can contribute:

1. Reporting bug or making feature requests [here](https://github.com/marzer/noexcept/issues/new)
2. Opening a pull request (⚠&#xFE0F; _caveat - see below_)
3. Becoming a [sponsor] ❤&#xFE0F;

<br>

## WG21 C++ Proposal

This project is an implementation of a C++ library proposal I'm in the process of
putting together, with the intent of having these traits become part of the standard's
`<type_traits>`library. You can read the paper [here](https://marzer.github.io/noexcept/).

[noexcept.hpp]: include/mz/noexcept.hpp
[license]: ./LICENSE
[cpp_compilers]: https://en.cppreference.com/w/cpp/compiler_support
[gitter]: https://gitter.im/marzer/community
[sponsor]: https://github.com/sponsors/marzer
