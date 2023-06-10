#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - adds positive numbers
 *
 * @argc: number of arguments
 * @argv: array of strings
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int n, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	for (n = 1; n < argc; n++)
	{
		int m = 0;

		while (argv[n][m])
		{
			if (!isdigit(argv[n][m]))
			{
				printf("Error\n");
				return (1);
			}
			m++;
		}
		sum += atoi(argv[n]);
	}
	printf("%d\n", sum);
	return (0);
}
