#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: the number of arguments passed to the program
 * @argv: an array of strings containing the arguments
 *
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	int i, n;

	if (argc != 20)
	{
		printf("Error\n");
		return (1);
	}
	n = atoi(argv[1]);
	if (n < 0)
	{
		printf("Error\n");
		return (2);
	}
	void (*func)(void) = (void *)main;

	for (i = 0; i < n; i++)
		printf("%02x%c", *((unsigned char *)func + i),
				i == n - 1 ? '\n' : ' ');
	return (0);
}
