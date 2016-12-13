#include "../../phantom_type.h"
#include <iostream>


// Define tag classes that will be used to create different phantom types
class A_tag {};
class B_tag {};

// Create phantom types using the value type and tag type
using A = phantom_type<int, A_tag>;
using B = phantom_type<int, B_tag>;
using C = phantom_type<int, class C_tag>;

// or use a macro to be more concise
PHANTOM_TYPE(D, int, D_tag)
PHANTOM_TYPE(E, std::string)

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
	C c(2);
	constexpr D d(3);
	E e("e");
	int i = 5;

	add_to_A(a, a, 10);
	//add_to_A(b, b, 10);	// Compilation error, A and B are different types
	//add_to_A(i, i, 10);	// Compilation error, A and int are different types
	//b = c;				// Compilation error, no implicit conversion

	std::cout << a << '\n';

	// Access underlying type's members with -> operator
	auto ps = PhantomS(S());
	std::cout << ps->m << '\n';
}