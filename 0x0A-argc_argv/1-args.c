#include <stdio.h>
#include "main.h"

/**
 * main - prints the number of arguments passed to it
 *
 * @argc: number of arrays
 * @argv: arrays of arguments
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	(void) argv;
		printf("%d\n", argc - 1);
		return (0);
}
