#include "main.h"
#include <stdarg.h>

/**
 * get_width - Calculates the width of the input
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed
 * @list: allows access to the variable arguments
 *
 * Return: Precision.
 */

int get_width(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int width = 0;
	
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width = width * 10 + (format[curr_i] - '0');
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
