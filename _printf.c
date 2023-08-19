#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"
#include <string.h>

/**
 * _printf - Entry point.
 * Description: This is an exact replica of
 * the printf function in c.
 * @format: output format.
 * Return: int
 */

int _printf(const char *format, ...)
{
	int i;
	int len = 0;
	int print_flag = 0;
	int flag = 0;
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			len += _putchar(format[i]);
			continue;
		}
		if (format[i + 1] == '%')
		{
			len += _putchar('%');
			i++;
			flag = 1;
			continue;
		}

		if (format[i + 1] == '\0' && format[i] == '%')
		{
			return (-1);
		}
		if (format[i + 1] == '\0')
		{
			return (len);
		}

		print_flag = identify(format[i + 1], args);

		if (print_flag == -1 || print_flag != 0)
		{
			i++;
		}
		if (print_flag > 0)
		{
			len += print_flag;
		}
		if (print_flag == 0 && flag == 0)
		{
			_putchar('%');
			len++;
		}
	}
	va_end(args);
	return (len);
}

