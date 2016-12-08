# phantom_type
Header for creating phantom types.

## Example
```C++
#include "../../phantom_type.h"
#include <iostream>


// Define tag classes that will be used to create different phantom types
class A_tag {};
class B_tag {};

// Create phantom types using the value type and tag type
using A = phantom_type<int, A_tag>;
using B = phantom_type<int, B_tag>;

// or use a macro to be more concise
PHANTOM_TYPE(C, int, C_tag)

// Takes A phantom type
void add_to_A(A& a, int x)
{
	a += x;
}

int main()
{
	A a = 0;
	B b = 1;
	C c = 2;
	int i = 3;

	add_to_A(a, 4);
	//add_to_A(b, 4);	// Compilation error, A and B are different types
	//add_to_A(i, 4);	// Compilation error, A and int are different types
	//b = c;			// Compilation error, no implicit conversion

	std::cout << a << '\n';
}
```

## License
MIT
