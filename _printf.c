#include "main.h"
/**
 * _printf - prints formatted data to stdout
 * @format: string that contains the format to print
 * Return: number of characters written
 */
int _printf(const char *format, ...)
{
	int fresult = 0;
	va_list args;

	conv_t funcs[] = {
		{"c", _print_char},
		{"s", _print_string},
		{"%", _print_percent},
		{"d", _print_int},
		{"i", _print_int},
		{NULL, NULL}
	};


	if (format == NULL)
		return (-1);
	va_start(args, format);
	fresult = print(format, funcs, args);
	va_end(args);
	return (fresult);
}
