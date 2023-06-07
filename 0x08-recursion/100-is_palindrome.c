#include <stdio.h>
#include "main.h"
#include <string.h>

/**
 * is_palindrome - returns 1 if a string is a palindrome
 *
 * @s: base case
 * Return: 1 if string is a palindrome, otherwise 0
 */

int is_palindrome(char *s)
{
	int len = strlen(s);

	for (int i = 0; i < len / 2; i++)
{
	if (s[i] != s[len - i - 1])
	{
		return (0);
	}
}
return (1);
}
