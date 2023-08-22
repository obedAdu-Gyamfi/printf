#include "main.h"

/**
 * get_flags - Calculates the flags specifier from a format string
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_flags(const char *format, int *i)
{
	int curr_i = *i + 1;
	int flags = 0;

	while (format[curr_i] == '-' || format[curr_i] == '0')
	{
		if (format[curr_i] == '-')
			flags |= FLAG_LEFT;
		else if (format[curr_i] == '0')
			flags |= FLAG_ZERO;

		curr_i++;
	}

	*i = (curr_i > *i + 1) ? curr_i - 1 : *i;

	return (flags);

}
