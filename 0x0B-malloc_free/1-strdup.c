#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: char
 * @
 *
 * Return: new_str on success, Otherwise NULL
 */

char *_strdup(char *str)
{
	size_t len;
	char *new_str;

	if (str == NULL)
	{
		return (NULL);
	}
	len = strlen(str);
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
	{
		return (NULL);
	}
	strcpy(new_str, str);
	return (new_str);
}
