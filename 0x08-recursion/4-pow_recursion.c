#include <stdio.h>
#include "main.h"

/**
 * _pow_recursion - returns the value of x raised to the power y
 *
 * @x: value
 * @y: power
 *
 * Return: if y is negative, Return -1 ,Otherwise void
 */

int _pow_recursion(int x, int y)
{
	if (y == 0)
	{
		return (1);
	}
	if (y < 0)
	{
		return (-1);
	}
	return (x * _pow_recursion(x, y - 1));
}
