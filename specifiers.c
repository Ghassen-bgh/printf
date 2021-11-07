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
	for (i = 0; i != '\0'; i++)
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