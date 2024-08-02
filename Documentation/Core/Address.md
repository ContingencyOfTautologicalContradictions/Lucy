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
#include <Meta/Same.hpp>
#include <Core/Address.hpp>

class Foo
{
	int data = 42;
public:
	int& operator&()
	{
		return data;
	}
};

template<class T> T* GetAddress(T& object)
{
	if constexpr(Lucy::Meta::Same<T*, decltype(&object)>)
		return &object;
	else
		return Lucy::Address(object);
}

int main()
{
	int meow = 42;
	std::println("The address of meow is {}", GetAddress(meow));

	Foo foo;
	std::println("The address of foo is {}", GetAddress(foo));
}
```