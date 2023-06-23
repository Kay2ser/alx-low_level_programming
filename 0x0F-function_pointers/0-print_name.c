#include <stdio.h>
#include "function_pointers.h"
/**
 * print_name - prints a name
 * @f: takes a char * argument and returns void
 * @name: string
 *
 * Return: nada
 */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}
