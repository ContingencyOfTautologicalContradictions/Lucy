# Lucy::Comparison
```css
LAST MODIFICATION - 27/03/2024
```

Declared at ``Core/Comparison.hpp``

```cpp
namespace Lucy
{
	enum class [[nodiscard]] Comparison : u8::type;
}
```

Indicates the result of a three-way comparison.


## Enumerators

### Less

```cpp
Less = 0u
```

Used when the result of the comparison happens to be less-than, in a strict order: if the result of ``a <=> b`` happens to be ``Less``, it means that ``a`` is less-than ``b``.


### Equal

```cpp
Equal = 1u
```

Used when the result of the comparison happens to be equal-to, in a strict order: if the result of ``a <=> b`` happens to be ``Equal``, it means that ``a`` is equal-to ``b``.


### Great

```cpp
Great = 2u
```

Used when the result of the comparison happens to be greater-than, in a strict order: if the result of ``a <=> b`` happens to be ``Great``, it means that ``a`` is greater-than ``b``.


## Usage

```cpp
#include <print>
#include <Core/Comparison.hpp>

class foo
{
public:
	int value;

	[[nodiscard]] constexpr Lucy::Comparison operator<=>(const foo other)
	{
		using enum Lucy::Comparison;
		if(value < other.value)
			return Less;
		else if(value == other.value)
			return Equal;
		return Great;
	}
};

int main()
{
	foo f, ff;
	f.value = 80u;
	ff.value = 42u;
	if((f <=> ff) == Lucy::Comparison::Great)
		std::println("80 is bigger than 42!");
}
```