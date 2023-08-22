#include "main.h"

/**
 * write_char - Prints a string
 * @c: char types
 * @buffer: Buffer array to handle print
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int write_char(char c, char buffer[], int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFFdSIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFFdSIZE - i - 2] = padd;

		if (flags & MINUS)
			return (write(1, &buffer[0], 1) + write(1, &buffer[BUFFdSIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFFdSIZE - i - 1], width - 1) + write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_num - Write a number using a buffer
 * @index: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Padding char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars
 */
int write_num(int index, char buffer[], int flags, int width, int precision, int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (precision == 0 && index == BUFFdSIZE - 2 && buffer[index] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision == 0 && index == BUFFdSIZE - 2 && buffer[index] == '0')
	{
		buffer[index] = padd = ' '; /* width is displayed with padding ' ' */
	}
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & MINUS && padd == ' ')/* Assign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & MINUS) && padd == ' ')/* Extra char to left of buffer */
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & MINUS) && padd == '0')/* Extra char to left of padding */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) + write(1, &buffer[index], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], length));
}

/**
 * write_number - Prints a string
 * @is_negative: List of arguments
 * @index: char types
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int write_number(int is_negative, int index, char buffer[], int flags, int width, int precision, int size)
{
	int length = BUFFdSIZE - index - 1;
	char padd = ' ', extra_c = 0;

	UNUSED(size);

	if ((flags & ZERO) && !(flags & MINUS))
		padd = '0';
	if (is_negative)
		extra_c = '-';
	else if (flags & PLUS)
		extra_c = '+';
	else if (flags & SPACE)
		extra_c = ' ';

	return (write_num(index, buffer, flags, width, precision, length, padd, extra_c));
}

/**
 * write_u - Writes an unsigned number
 *
 * @index: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 *
 * Return: Number of written chars
 */
int write_u(int is_negative, int index, char buffer[], int flags, int width, int precision, int size)
{
	/* The number is stored at the buffer's right and starts at position i */
	int length = BUFFdSIZE - index - 1;
	int i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);


	if (precision == 0 && index == BUFFdSIZE - 2 && buffer[index] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}

	if ((flags & ZERO) && !(flags & MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & MINUS) /* Assign extra char to left of buffer [buffer > padd] */
		{
			return (write(1, &buffer[index], length) + write(1, &buffer[0], i));
		}
		else /* Assign extra char to left of padding [padd > buffer] */
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[index], length));
		}
	}

	return (write(1, &buffer[index], length));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @index: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars
 */
int write_pointer(char buffer[], int index, int length, int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & MINUS && padd == ' ')/* Assign extra char to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & MINUS) && padd == ' ')/* Extra char to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], length));
		}
		else if (!(flags & MINUS) && padd == '0')/* Extra char to left of padding */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) + write(1, &buffer[index], length - (1 - padd_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], BUFFdSIZE - index - 1));
}
