/*
The MIT License (MIT)

Copyright (c) 2016 Yehonatan Ballas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#ifndef phantom_type_h
#define phantom_type_h


#include <type_traits>


/*
Phantom type template class.
*/
template <typename T, typename enable = void>
struct phantom_type
{
	phantom_type() = default;
	constexpr explicit phantom_type(const T& value) : value(value) {}
	constexpr explicit phantom_type(T&& value) : value(std::move(value)) {}

	// Convert to the underlying value
	operator T& () noexcept { return value; }
	constexpr operator const T& () const noexcept { return value; }

	// Access members of the underlying type
	T* operator->() { return &value; }
	constexpr const T* operator->() const { return &value; }

	T value;
};

// Specialize for class types to use inheritance
template <typename T>
struct phantom_type<T, typename std::enable_if_t<std::is_class<T>::value>> : T
{
	phantom_type() = default;
	constexpr explicit phantom_type(const T& value) : T(value) {}
	constexpr explicit phantom_type(T&& value) : T(std::move(value)) {}

	using T::T;
};


// Macro for concisely defining a phantom type
#define PHANTOM_TYPE(type_name, value_type) \
struct type_name : phantom_type<value_type> \
{\
    using phantom_type::phantom_type;\
};


#endif//phantom_type_h