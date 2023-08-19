#include <stdio.h>
#include "main.h"

/**
 * _strlen - Entry point.
 * Description: This is function that determines the
 * length of string.
 * It behaves the same ways as the strlen function in c.
 *
 * @s: string
 *
 * Return: len
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
