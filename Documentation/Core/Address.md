```haskell
Documentation of Core/Address.hpp
```
# Functions

## Lucy::Address

```cpp
namespace Lucy
{
	template<class T> [[nodiscard]] inline constexpr auto Address(T& object) noexcept -> T*;
}
```

Computes the address of ``object``.


### Parameters

- ``object``: The object to take the address from.


### Return

The address of ``object`` in the form of a pointer.


### Example

```cpp
#include <print>
#include <Core/Address.hpp>

int main()
{
	int meow = 42;
	std::println("The address of meow is {}", Lucy::Address(meow));
}
```