#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int _isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

/**
 * _strlen - computes the length of a string
 * @s: the string to compute the length of
 *
 * Return: the length of the string
 */
unsigned int _strlen(char *s)
{
    unsigned int len = 0;

    while (*s++)
        len++;

    return (len);
}

/**
 * _puts - prints a string to stdout
 * @s: the string to print
 *
 * Return: the number of characters printed
 */
int _puts(char *s)
{
    int len = _strlen(s);

    return (write(1, s, len));
}

/**
 * print_error - prints an error message and exits with status 98
 */
void print_error(void)
{
    _puts("Error\n");
    exit(98);
}

/**
 * multiply - multiplies two numbers represented as strings
 * @s1: the first number
 * @s2: the second number
 *
 * Return: the result of the multiplication, represented as a string
 */
char *multiply(char *s1, char *s2)
{
	unsigned int len1, len2, len_res, i, j, carry;
	int *res;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	if (len1 == 0 || len2 == 0)
		return ("0");

    len_res = len1 + len2;

    res = calloc(len_res, sizeof(int));
    if (res == NULL)
        return (NULL);

    for (i = len1 - 1; i != (unsigned int)-1; i--)
    {
        carry = 0;
        for (j = len2 - 1; j != (unsigned int)-1; j--)
	{
            carry += (s1[i] - '0') * (s2[j] - '0') + res[i + j + 1];
            res[i + j + 1] = carry % 10;
            carry /= 10;
        }
        if (carry)
            res[i + j + 1] = carry;
    }

    while (*res == 0 && len_res > 1)
    {
        res++;
        len_res--;
    }

    for (i = 0; i < len_res; i++)
        res[i] += '0';

    return ((char *)res);
}

/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments
 * @argv: an array of strings containing the arguments
 *
 * Return: 0 if successful, 98 if there is an error
 */
int main(int argc, char **argv)
{
	char *res;

	if (argc != 3)
		print_error();
	for (int i = 1; i < argc; i++)
	{
		char *s = argv[i];
		while (*s)
		{
			if (!_isdigit(*s))
				print_error();
			s++;
		}
	}

	res = multiply(argv[1], argv[2]);
	if (res == NULL)
		return (98);
	_puts(res);
	_puts("\n");
	free(res);
	return (0);
}
