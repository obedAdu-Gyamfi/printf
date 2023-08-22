#include <stddef.h>
#include "main.h"
#include <stdarg.h>
/**
 * print_int - Entry point.
 * Description: This is a function that prints an integer
 * @args: list of variables.
 * Return: int
 */
int print_int(va_list args)
{
	int len = 0;
	int count = 0;
	int p, j, digit, n;
	int number;

	n = va_arg(args, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
		}
		number = n;
		while (number != 0)
		{
			number /= 10;
			len++;
		}
		p = 1;
		for (j = 1; j <= len - 1; j++)
		{
			p *= 10;
		}
		for (j = 1; j <= len; j++)
		{
			digit = n / p;
			if (n < 0)
			{
				_putchar((digit * -1) + 48);
			}
			else
			{
				_putchar(digit + '0');
			}
			count++;
			n -= digit * p;
			p /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
/**
 * print_hex - Entry point
 * Description: This function prints and unsigned int
 * in hexadecimal
 * @n: unsigned int to be printed
 * @c: Casing (lower and upper)
 * (0 for lower case, 1 for upper case)
 * Return: size of output
 */
int print_hex(unsigned int n, unsigned int c)
{
	unsigned int len, p;
	unsigned int digit, j, number;
	int count = 0;
	char d;

	if (n != 0)
	{
		number = n;
		len = 0;
		if (c)
		{
			d = 'A' - ':';
		}
		else
		{
			d = 'a' - ':';
		}
		while (number != 0)
		{
			number /= 16;
			len++;
		}
		p = 1;
		for (j = 1; j <= len - 1; j++)
		{
			p *= 16;
		}
		for (j = 1; j <= len; j++)
		{
			digit = n / p;
			if (digit < 10)
			{
				_putchar(digit + '0');
			}
			else
			{
				_putchar(digit + '0' + d);
			}
			count++;
			n -= digit * p;
			p /= 16;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
/**
 * print_x - prints lower case
 * @x: unsigned int to print.
 * Return: size of output
 */
int print_x(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}
/**
 * print_X - Prints Upper case
 * @X: unsigned int to print
 * Return: size of output
 */
int print_X(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}

/**
 * print_octal - Prints the octal number of an
 * unsigned integer.
 * @args: list of unsigned integers.
 * Return: int
 */
int print_octal(va_list args)
{
	unsigned int len, p, digit, number;
	unsigned int j, count = 0, n;

	n = va_arg(args, int);
	if (n != 0)
	{
		number = n;
		len = 0;

		while (number != 0)
		{
			number /= 8;
			len++;
		}
		p = 1;
		for (j = 1; j <= len - 1; j++)
		{
			p *= 8;
		}
		for (j = 1; j <= len; j++)
		{
			digit = n / p;
			if (n > 8)
			{
				_putchar(digit % 8 + '0');
			}
			else
			{
				_putchar(digit + '0');
			}
			count++;
			n -= digit * p;
			p /= 8;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
