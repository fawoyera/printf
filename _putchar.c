#include <unistd.h>
/**
 * _putchar - print a single char to stdout
 * @c: the char
 *
 * Return: void
 */
void _putchar(char c)
{
	write(1, &c, 1);
}
