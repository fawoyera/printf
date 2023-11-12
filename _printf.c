#include "main.h"
#include <stddef.h>

int len(char *str);
/**
 * _printf - print formatted output
 * @format: the format specifiers
 *
 * Return: the number of chars printed
 */
int _printf(const char *format, ...)
{
	int i = 0, j, count = 0;
	char *string;
	va_list args;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
			_putchar(format[i]);
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				_putchar('%'), count++;
				va_end(args);
				return (count);
			}
			i++;
			if (format[i] == 'c')
				_putchar(va_arg(args, int)), count++;
			else if (format[i] == 's')
			{
				string = va_arg(args, char*);
				if (string == NULL)
					string = "(nil)";
				for (j = 0; j < len(string); j++)
					_putchar(string[j]), count++;
			}
			else
			{
				_putchar('%'), count++;
				_putchar(format[i]), count++;
			}
		}
		i++;
	}
	va_end(args);

	return (count);
}
/**
 * len - find the length of a string
 * @str: the string
 *
 * Return: length of string
 */
int len(char *str)
{
	int i = 0;
	char *string;

	string = str;
	while (*string++)
		i++;

	return (i);
}
