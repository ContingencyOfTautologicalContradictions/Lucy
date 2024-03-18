# Lucy::Abort
```css
LAST MODIFICATION - 18/03/2024
```

Declared at ``Core/Abort.hpp``

```cpp
namespace Lucy
{
	[[noreturn]] auto Abort() noexcept -> void;
}
```

Terminates the running program abnormally.

The destructors of any created instance that remains within its lifetime are not invoked.


## Parameters

None.


## Return

None.


## Exceptions

None.


## Usage

```cpp
#include <new>
#include <print>
#include <Core/Abort.hpp>

void print_value(int const& value)
{
	std::println("The value is {}", value);
}

int main()
{
	int* value = new(std::nothrow) int(42);
	if(value == nullptr)
		Lucy::Abort(); // If Abort is called, the following code won't be executed
	print_value(*value);
	delete value;
}
```