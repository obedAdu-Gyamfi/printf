#include "main.h"

/**
 * print_octal - Prints an ocatl number
 *
 * @args: List of arguments
 * @buffer: Buffer Array
 * @flags: Flags used
 *
 * Return: number of characters to be printed
 */

long int convert_size_u();

int print_octal(va_list args, char buffer[], int flags, int precision, int size)
{
	int i = BUFFdSIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int initial = num;

	num = convert_size_u(num, size);
	if (num == 0)
	{
		buffer[i--] = '0';
	}

	buffer[BUFFdSIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & HASH && initial != 0)
		buffer[i--] = '0';

	i++;

	return (write_u(0, i, buffer, flags, precision, size));
}

/**
 * convert_size_u - Casts a number to the specified size
 *
 * @num: Number to be casted
 * @size: Size to cast @num to
 *
 * Return: Casted value.
 */

long int convert_size_u(unsigned long int num, int size)
{
	if (size == LONG)
		return num;
	else if (size == SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
