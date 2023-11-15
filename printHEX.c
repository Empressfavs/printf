#include "main.h"

/**
 * print_HEX - prints an hexgecimal number.
 * @val: arguments.
 * Return: counter.
 */
int print_HEX(va_list val)
{
	int j;
	int *arr;
	int counter = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int tem = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	arr = malloc(counter * sizeof(int));

	for (j = 0; j < counter; j++)
	{
		arr[j] = tem % 16;
		tem /= 16;
	}
	for (j = counter - 1; j >= 0; j--)
	{
		if (arr[j] > 9)
			arr[j] += 7;
		_putchar(arr[j] + '0');
	}
	free(arr);
	return (counter);
}

