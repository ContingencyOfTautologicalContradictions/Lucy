# Lucy::NullPointer
```css
LAST MODIFICATION - 17/03/2024
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

void foo(int* ptr)
{
	std::println("The value of the pointer is {}", *ptr);
}

void foo(Lucy::NullPointer)
{
	std::println("Oh no, a null pointer!");
}

int main()
{
	int a = 42, *b = &a;
	foo(b); // derives to foo(int*)
	foo(nullptr); // derives to foo(Lucy::NullPointer)
}
```