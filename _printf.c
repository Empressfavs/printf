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

	register int next_element = 0;

	va_start(num_args, format);
	if (*format != '%')
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				next_element += _putchar('%');
				continue;
			}
			/*while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			count += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *p);*/
		}
		else
			next_element += _putchar(*format);
	}
	_putchar(-1);
	va_end(num_args);
	return (next_element);
}
