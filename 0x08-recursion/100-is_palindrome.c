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
	int i = 0, j = len - 1;
	
	while (i < j)
	{
		if (s[i] != s[j])
		{
			return (0);
		}
		i++;
		j--;
	}
return (1);
}
