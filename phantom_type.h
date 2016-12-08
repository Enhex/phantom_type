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
#define PHANTOM_TYPE(type_name, value_type, tag_type) class tag_type{}; using type_name = phantom_type<value_type, tag_type>;


#endif//phantom_type_h