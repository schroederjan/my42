#include "./include/ft_printf.h"
#include <limits.h>
#include <math.h>

int main(void)
{
	ft_printf("String: %s, Character: %c\n", "Hello, world!", 'A');

	ft_printf("Integer: %d, Unsigned: %u, Hex (lowercase): %x, Hex (uppercase): %X\n", -123, 123, 456, 456);
	ft_printf("Floating point: %f\n", 123.456);

	int num = 42;
	ft_printf("Pointer Address: %p\n", (void *)&num);

	ft_printf("String: %s, Int: %d, Char: %c, Unsigned: %u, Hex: %x\n", "Test", -42, 'Z', 42, 42);

	ft_printf("Width 10: '%10s', Precision 3: '%.3s'\n", "Hello", "Hello");
	ft_printf("Width and precision for int: '%10.5d'\n", -42);
	ft_printf("Width and precision for float: '%10.2f'\n", 123.456);

	ft_printf("Very large int: %d\n", INT_MAX);
	ft_printf("Very small int: %d\n", INT_MIN);
	ft_printf("Empty string: '%s'\n", "");
	ft_printf("Infinity: %f, NaN: %f\n", INFINITY, NAN);

	// NOT SUPPORTED
	ft_printf("Complex format: '%-10.3d'\n", 42);
	ft_printf("Long long int: '%lld'\n", (long long)1234567890123);
	ft_printf("Custom format: %R\n", "Some custom format or behavior");
}

