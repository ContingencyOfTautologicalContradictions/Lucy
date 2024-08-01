```haskell
Documentation of Core/Abort.hpp
```
# Functions

## Lucy::Abort

```cpp
namespace Lucy
{
	[[noreturn]] auto Abort() noexcept -> void;
}
```

Calls the handlers signalled with [Lucy::Action::Abort](./Signal.md), if any, and causes the running process to abnormally terminate without cleaning the alive resources, in that strict order.


### Parameters

None.


### Return

None.


### Example

```cpp
#include <print>
#include <cstdlib>
#include <Core/Abort.hpp>

int main()
{
	int* pointer;
	if((pointer = reinterpret_cast<int*>(std::malloc(4096))) == nullptr)
		Lucy::Abort();
	else
		std::println("the memory was allocated at {}!", pointer);
}
```