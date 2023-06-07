#include <stdio.h>
#include "main.h"

int actual_sqrt_recursion(int n, int j);

/**
 * _sqrt_recursion - returns the natural square root of a number
 *
 * @n: base case
 *
 * Return: -1 if n does not have a natural sqrt, Otherwise void
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (actual_sqrt_recursion(n, 0));
}

/**
 * actual_sqrt_recursion - finds the ntrl sqrt of a numbers
 *
 * @n: integer to calculate sqrt of
 * @j: iterates
 *
 * Return: sqrt
 */

int actual_sqrt_recursion(int n, int j)
{
	if (j * j > n)
		return (-1);
	if (j * j == n)
		return (j);
	return (actual_sqrt_recursion(n, j + 1));
}
