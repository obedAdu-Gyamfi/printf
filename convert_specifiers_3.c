#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stdarg.h>

/**
 * print_unsigned - Entry point.
 * Description: This is a function that prints
 * unsigned int.
 * @args: unsigned int.
 * Return: int
 */
int print_unsigned(va_list args)
{
	unsigned int len = 0;
	unsigned int p = 1;
	unsigned int j, n;
	unsigned int digit, number;
	int count = 0;

	n = va_arg(args, unsigned int);
	if (n != 0)
	{
		number = n;
		while (number != 0)
		{
			number /= 10;
			len++;
		}
		for (j = 1; j <= len - 1; j++)
		{
			p *= 10;
		}
		for (j = 1; j <= len; j++)
		{
			digit = n / p;
			_putchar(digit + '0');
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
 * print_rot - Rot13 encoding of a string.
 * @args: string to convert.
 * Return: int.
 */
int print_rot(va_list args)
{
	int j, i, count = 0;
	char *R;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";

	R = va_arg(args, char *);
	if (R == NULL)
	{
		R = "(null)";
	}
	for (j = 0; R[j] != '\0'; j++)
	{
		for (i = 0; input[i] != '\0'; i++)
		{
			if (R[j] == input[i])
			{
				_putchar(output[i]);
				count++;
				break;
			}
		}
	}
	return (count);
}

/**
 * binary - prints  out a converted unsigned int into binary
 * @n: unsgined int
 * @len: counter pointer.
 * Return void;
 */
void binary(unsigned int n, int *len)
{
	if (n > 1)
	{
		*len += 1;
		binary(n >> 1, len);
	}
	_putchar((n & 1) + '0');
}

/**
 * print_ui_b - Entry point.
 * @args: list of variables.
 * Return: int
 */
int print_ui_b(va_list args)
{
	unsigned int n;
	int len;
	int *ptr;

	n = va_arg(args, unsigned int);
	ptr = &len;
	binary(n, ptr);

	ptr = NULL;
	return (len);
}

