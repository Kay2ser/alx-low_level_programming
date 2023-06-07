#include <stdio.h>
#include "main.h"

/**
 * _puts_recursion - prints a string
 * @str: string to be printed
 * Return: Returns void
 */

void _puts_recursion(char *str)
{
	if (*str == '\0')
	{
		printf("\n");
		return;
	}
	else
	{
		printf("%c", *str);
		_puts_recursion(str + 1);
	}
}
