#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>

/**
 * identify - Entry point.
 * Description: Identifiers the specifier used
 * after %
 * @c: character specifier.
 * @args: list of variables
 * Return: int
 */
int identify(char c, va_list args)
{
	int i;
	d_type data_type[] = {
		{"c", _print_char},
		{"s", print_str},
		{"d", print_int},
		{"i", print_int},
		{"b", print_ui_b},
		{"u", print_unsigned},
		{"x", print_x},
		{"X", print_X},
		{"R", print_rot},
		{NULL, NULL}
	};

	for (i = 0 ; data_type[i].sp != NULL; i++)
	{
		if (data_type[i].sp[0] == c)
		{
			return (data_type[i].f(args));
		}
	}
	return (0);
}
