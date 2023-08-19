#include <unistd.h>
#include "main.h"

/**
 * _putchar - Writes a character to the standard output.
 * @c: character to write.
 * Return: char
 */
int _putchar(char c)
{
	return (write(1,&c,1));
}
