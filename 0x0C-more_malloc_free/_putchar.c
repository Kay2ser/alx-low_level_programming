#include <unistd.h>
#include "main.h"

/**
 * _putchar - outputs a single charachter to the standard 
 * output stream
 *
 * @c: charachter to print
 *
 * Return: 1 on success, Otherwise -1
 */

int _putchar(char c)
{
	return (write(1,  &c, 1));
}
