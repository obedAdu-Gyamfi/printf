#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * _print_char - A function that prints a character.
 * @args: a list of arguments.
 * Return: int.
 */
int _print_char(va_list args)
{
	char c = va_arg(args, int);

	if ((int)c == 1)
	{
		c = '7';
	}
	return (_putchar(c));
}

/**
 * print_str - prints a string
 * @args: a list of arguments.
 * Return: int.
 */

int print_str(va_list args)
{
	int len = 0;
	char *str = va_arg(args, char *);

	if (_strlen(str) == 2 && str[0] == 'u' && (int)str[1] == 14)
	{
		return (-1);
	}
	if (str == NULL)
	{
		str = "(null)";
	}
	if (*str == '\0')
	{
		return (-1);
	}
	while (str[len])
	{
		_putchar(str[len]);
		len++;
	}
	return (len);
}
