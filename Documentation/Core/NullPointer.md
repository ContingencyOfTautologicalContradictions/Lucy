# Lucy::NullPointer
```css
LAST MODIFICATION - 18/03/2024
```

Declared at ``Core/NullPointer.hpp``

```cpp
namespace Lucy
{
	using NullPointer;
}
```

The type of the null pointer literal (``nullptr``).


## Usage

```cpp
#include <print>
#include <Core/NullPointer.hpp>

void print_value(int* ptr)
{
	std::println("The value of the pointer is {}", *ptr);
}

void print_value(Lucy::NullPointer)
{
	std::println("Oh no, a null pointer!");
}

int main()
{
	int a = 42, *b = &a;
	print_value(b); // derives to print_value(int*)
	print_value(nullptr); // derives to print_value(Lucy::NullPointer)
}
```