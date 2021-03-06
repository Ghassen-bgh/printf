#include"main.h"
/**
 * _print_char - Prints character.
 * @list: list of arguments.
 * Return: character to print
 */
int _print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}
/**
 * _print_string - Print a string.
 * @list: list of arguments.
 * Return: string to print.
 */
int _print_string(va_list list)
{
	int i;
	char *s;

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	return (i);
}

/**
 * _print_percent - prints '%'.
 * @list: list of arguments.
 * Return: '%'.
 */
int _print_percent(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}

/**
 * _print_int - prints an integer
 * @args: argument to print
 * Return: number to print
 */

int _print_int(va_list args)
{
	int n = va_arg(args, int);
	unsigned int x;
	int i = 0;
	int d = 1;

	if (n < 0)
	{
		_putchar('-');
		n = n * -1;
		i++;
	}
	x = n;
	while ((x / d) > 9)
		d = d * 10;
	while (d > 0)
	{
		_putchar(x / d + '0');
		x = x % d;
		d = d / 10;
		i++;
	}
	return (i);
}

/**
 * _print_binary - convert an integer to binary (base 2).
 *
 * @arg: the list of arguments.
 *
 *  Return: number of printed element.
 */
int _print_binary(va_list arg)
{
	unsigned int binary[32];
	int i = 0;
	unsigned int n = 0, count = 0;

	n = va_arg(arg, unsigned int);

	if (n <= 1)
	{
		_putchar(n + '0');
		count++;
	}
	else
	{
		while (n > 0)
		{
			binary[i] = n % 2;
			n = n / 2;
			i++;
		}
		for (i = i - 1; i >= 0; i--)
		{
			_putchar(binary[i] + '0');
			count++;
		}
	}
	return (count);
}
