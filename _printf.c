#include "main.h"
/**
 * _printf - writes the string format to stdout
 * @format: The string to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printf(const char *format, ...)
{
	va_list num_args;
	int next_element = 0;

	va_start(num_args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			next_element++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				char count = va_arg(num_args, int);

				write(1, &count, 1);
				next_element++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(num_args, char*);

				int len = 0;
				while (str[len] != '\0')
					len++;
				write(1, str, len);
				next_element = next_element + len;
			}
			else if (*format == '%')
			{
				return (-1);
				next_element++;
			}
		}
		format++;
	}
	va_end(num_args);
	return (next_element);
}
