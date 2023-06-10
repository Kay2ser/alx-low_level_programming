#include <stdio.h>
#include "main.h"

/**
 * main - program that prints its name
 *
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])

{
	if (argc > 0)
	{
		printf("%s\n", argv[0]);
	}
	return (0);
}
