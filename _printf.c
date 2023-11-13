#include "main.h"
#include <stddef.h>

int len(char *str);
int print_num(int num);
/**
 * _printf - print formatted output
 * @format: the format specifiers
 *
 * Return: the number of chars printed
 */
int _printf(const char *format, ...)
{
	int i = 0, j, count = 0, num;
	char *string;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
			_putchar(format[i]), count++;
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			i++;
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(args, int)), count++;
					break;
				case 's':
					string = va_arg(args, char*);
					if (string == NULL)
						string = "(null)";
					for (j = 0; j < len(string); j++)
						_putchar(string[j]), count++;
					break;
				case 'd':
					num = va_arg(args, int);
					count += print_num(num);
					break;
				case 'i':
					num = va_arg(args, int);
					count += print_num(num);
					break;
				case '%':
					_putchar('%'), count++;
					break;
				default:
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

/**
 * print_num - print the signed num to stdout
 * @num: the num
 *
 * Return: number of chars printed
 */
int print_num(int num)
{
	int i = 0, j = 0, tmp_num, count = 0;
	char *str_num, *tmp_str_num;

	if (num < 0)
	{
		_putchar('-'), count++;
		num = 0 - num;
	}
	tmp_num = num;
	while (tmp_num > 0)
	{
		tmp_num /= 10;
		i++;
	}
	str_num = malloc(sizeof(char) * (i + 1));
	if (str_num == NULL)
		exit(-1);
	str_num[i] = '\0';
	while (num > 0)
	{
		tmp_num = num % 10;
		str_num[--i] = tmp_num + '0';
		num /= 10;
	}
	tmp_str_num = str_num;
	while (*tmp_str_num++)
		j++;
	for (i = 0; i < j; i++)
		_putchar(str_num[i]), count++;

	return (count);

}
