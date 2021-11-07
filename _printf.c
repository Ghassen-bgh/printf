#include "main.h"
/**
 * _printf - prints formatted data to stdout
 * @format: string that contains the format to print
 * Return: number of characters written
 */
int _printf(const char *format, ...)
{
	int i, j, fvalue;
	int fresult = 0;
	va_list args;

	conv_t funcs[] = {
		{"c", _print_char},
		{"s", _print_string},
		{"%", _print_percent},
		{NULL, NULL}
	};


	if (format == NULL)
		return (-1);
	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; funcs[j].sym != NULL; j++)
			{
				if (format[i + 1] == funcs[j].sym[0])
				{
					fvalue = funcs[j].f(args);
					if (fvalue == -1)
						return (-1);
					fresult += fvalue;
					break;
				}
			}
		if (funcs[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					fresult = fresult + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			fresult++;
		}
	}
	return (fresult);
	va_end(args);
}
