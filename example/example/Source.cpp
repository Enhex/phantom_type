#include "../../phantom_type.h"
#include <iostream>


// Create phantom types using the value type and tag type
struct A : phantom_type<int> { using phantom_type::phantom_type; };
struct B : phantom_type<int> { using phantom_type::phantom_type; };

// or use a macro to be more concise
PHANTOM_TYPE(C, int)
PHANTOM_TYPE(D, std::string)

// Will be used to show accessing members
struct S
{
	int m = 0;
};
PHANTOM_TYPE(PhantomS, S)

// Takes A phantom type
void add_to_A(A& a, A a2, int x)
{
	a += a2 + x;
}

int main()
{
	A a(0);
	B b(1);
	constexpr C c(2);
	D d("c");
	int i = 3;

	add_to_A(a, a, 10);
	//add_to_A(b, b, 10);	// Compilation error, A and B are different types
	//add_to_A(i, i, 10);	// Compilation error, A and int are different types
	//b = c;				// Compilation error, no implicit conversion

	std::cout << a << '\n';

	// Access underlying type's members with -> operator
	auto ps = PhantomS(S());
	std::cout << ps->m << '\n';
}