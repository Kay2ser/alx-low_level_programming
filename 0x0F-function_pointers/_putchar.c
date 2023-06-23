#include <unistd.h>
#include "main.h"

/**
 * _putchar -wrties the character c to stdout
 * @c: The charachter to print
 *
 * Return: On success 1, on error -1
 */
int _putchar(char *c)
{
	return (write(1, &c, 1));
}
