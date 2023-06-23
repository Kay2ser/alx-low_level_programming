#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - prints a variable number of integers to the console
 * @separator: the string to print between integers (or NULL if none)
 * @n: the number of integer arguments
 * @...: the integer arguments to print
 *
 * Return: void
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(args, int));
		if (separator != NULL && i != n - 1)
		{
			printf("%s", separator);
		}
	}
	va_end(args);

	printf("\n");
}

