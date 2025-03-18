#include "ft_printf.h"

int	main()
{
	char	ptr[] = "abcdE";
	int	entero = 84;
	int	hex = 5498;
	unsigned int	int_max = INT_MAX;

	ft_printf("Character: %c\n", '0');
	printf("Character: %c\n", '0');
	ft_printf("String: %s\n", ptr);
	printf("String: %s\n", ptr);
	ft_printf("Pointer: %p\n", ptr);
	printf("Pointer: %p\n", ptr);
	ft_printf("Decimal: %d\n", entero);
	printf("Decimal: %d\n", entero);
	ft_printf("Entero: %i\n", entero);
	printf("Entero: %i\n", entero);
	ft_printf("Unsigned Int: %u\n", int_max);
	printf("Unsigned Int: %u\n", int_max);
	ft_printf("Hexadecimal min: %x\n", hex);
	printf("Hexadecimal min: %x\n", hex);
	ft_printf("Hexadecimal may: %X\n", hex);
	printf("Hexadecimal may: %X\n", hex);
	ft_printf("Porcentaje: %%\n");
	printf("Porcentaje: %%\n");
	ft_printf("Porcentaje raw: aaa%%\n");
	printf("Porcentaje raw: aaa%%\n");
	// NULL
	ft_printf("Pointer: %p\n", NULL);
	printf("Pointer: %p\n", NULL);
	ft_printf("String: %s\n", (const char *)NULL);
	printf("String: %s\n", (const char *)0);
	// Multiple params
	ft_printf("MultipleFT: %s %s\n", "String1", "String2");
	printf("MultipleFT: %s %s\n", "String1", "String2");
	
	// LIMITS
	ft_printf("FT: %X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("Or: %X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, (unsigned int)LONG_MAX, (unsigned int)LONG_MIN, (unsigned int)ULONG_MAX, 0, -42);
	return (0);
}
