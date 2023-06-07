#include <stdio.h>
#include "main.h"

int actual_prime(int n, int j);

/**
 * is_prime_number - checks for prime number
 * @n: integer to be checked
 *
 * Return: 1 if the input integer is a prime number, Otherwise 0
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (actual_prime(n, n - 1));
}

/**
 * actual_prime - calculates if a no is prime
 * @n: int to be checked
 * @j: iterator
 * Return: Returns 1 if n is prime, otherwise 0
 */

int actual_prime(int n, int j)
{
	if (j == 1)
		return (1);
	if (n % j == 0 && j > 0)
		return (0);
	return (actual_prime(n, j - 1));
}
