#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - prints strings
 * @separator: the string to print between strings (or NULL if none)
 * @n: the number of string arguments
 * @...: the string arguments to print
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);
		printf("%s", (str == NULL) ? "(nil)" : str);
		if (separator != NULL && i != n - 1)
		{
			printf("%s", separator);
		}
	}
	va_end(args);
	printf("\n");
}
