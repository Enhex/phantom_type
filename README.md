# phantom_type
Header for creating phantom types.

## Example
```C++
#include <phantom_type.h>
#include <iostream>

PHANTOM_TYPE(PhantomInt, int)

void print(PhantomInt& x) {
	std::cout << x << std::endl;
}

int main()
{
	int i = -1;
	PhantomInt pi(1);

	print(pi);
	//print(i);	// Compilation error, PhantomInt and int are different types
}
```
For more examples see [this](example/example/Source.cpp).

## License
MIT
