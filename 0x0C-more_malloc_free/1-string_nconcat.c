#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatenates two strings.
 * @s1: the first string to concatenate.
 * @s2: the second string to concatenate.
 * @n: the maximum number of bytes to use from s2.
 *
 * Return: a pointer to the newly allocated space in memory,
 *         containing s1, followed by the first n bytes of s2,
 *         and a null terminator, or NULL if the function fails.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int s1_len = 0, s2_len = 0, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[s1_len] != '\0')
		s1_len++;
	while (s2[s2_len] != '\0')
		s2_len++;
	if (n >= s2_len)
		n = s2_len;
	concat = malloc(sizeof(char) * (s1_len + n + 1));

	if (concat == NULL)
		return (NULL);
	for (i = 0; i < s1_len; i++)
		concat[i] = s1[i];
	for (j = 0; j < n; j++)
		concat[i + j] = s2[j];
	concat[i + j] = '\0';
	return (concat);
}
