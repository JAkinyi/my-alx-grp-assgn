#include <stdlib.h>
#include "main.h"
#include <stdarg.h>

/**
  * _printf - produces output according to format
  * @format: character or string
  * Return: the number of characters printed
  */

int _printf(const char *format, ...)
{
	int i;
	va_list ap;
	char *tmp;
	int len = 0;

	va_start(ap, format);
	i = 0;
	while(format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				_putchar((char) va_arg(ap, int));
				len++;
				i++;
			}

			if (format[i + 1] == 's')
			{
				tmp = va_arg(ap, char*);
				while (tmp[len] != '\0')
				{
					_putchar(tmp[len]);
					len++;
				}
				i++;
			}
		}
		else
		{
			_putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (len);
}
