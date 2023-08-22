#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable
 *
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags: included flags
 *
 * Return: The number of characters printed
 */

int print_pointer(va_list types, char buffer[], int flags)
{
	char extra_c = 0, padd = ' ';
	int index = BUFFdSIZE - 2;
	int length = 2;
	int padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);


	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFdSIZE - 1] = '\0';
	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[index--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & ZERO) && !(flags & MINUS))
		padd = '0';

	if (flags & PLUS)
		extra_c = '+', length++;
	else if (flags & SPACE)
		extra_c = ' ', length++;

	index++;

	*return (write_pointer(buffer, index, length, flags, padd, extra_c, padd_start));
}

/**
 * print_unprintable - Prints the value of a pointer variable
 *
 * @types: List of arguments
 * @buffer: Buffer array
 *
 * Return: The number of characters printed
 */

int print_unprintable(va_list types, char buffer[])
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * print_reverse - Prints the value of a pointer variable
 *
 * @args: List of arguments
 *
 * Return: The number of characters printed
 */

int print_reverse(va_list args)
{
	char *str = va_arg(args, char *);
	int i, count = 0;

	if (str == NULL)
	{
		str = ")Null(";
	}

	for (i = 0; str[i]; i++)
	{
		for (i = i - 1; i >= 0; i--)
		{
			char z = str[i];

			write(1, &z, 1);
			count++;
		}
	}

	return (count);
}
