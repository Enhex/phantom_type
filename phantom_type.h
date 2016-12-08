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


/*
Phantom type template class.
Use an empty class as a Tag to create a new phantom type for T.
*/
template <typename T, typename Tag>
class phantom_type
{
public:
	phantom_type(T value) : value(value) {}
	operator T& () noexcept { return value; }
	T& get() noexcept { return value; }

private:
	T value;
};


// Macro for concisely defining a tag class and type alias
#define PHANTOM_TYPE(type_name, value_type, tag_type) using type_name = phantom_type<value_type, class tag_type>;
#define PHANTOM_TYPE(type_name, value_type) using type_name = phantom_type<value_type, class type_name##_##value_type##_tag>;


#endif//phantom_type_h