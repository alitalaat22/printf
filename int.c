#include "main.h"
/**
*p_integer - a function that prints with recursion
*@n: int
*@count: pointer to sum of chars
*@flag: plus or ' '
*@is_start: 1 or 0
*/
void p_integer(long int n, int *count, char flag, int is_start)
{
	if (is_start)
	{
		if (n < 0)
		{
			my_putchar('-');
			(*count)++;
			n = -n;
		}
		else if (flag == '+' || flag == ' ')
		{
			my_putchar(flag);
			(*count)++;
		}
	}

	if (n / 10)
	{
		p_integer(n / 10, count, flag, 0);
	}
	my_putchar('0' + (n % 10));
	(*count)++;
}

/**
*my_integer - a function to i and d handle
*@args: arguments
*@flag: flag character
*@length_modifier: length char
*Return: num of char
*/
int my_integer(va_list args, char flag, char length_modifier)
{
long int index;
int counter = 0;

	switch (length_modifier)
	{
		case 'l':
			index = va_arg(args, long int);
			break;
		case 'h':
			index = (short int)va_arg(args, int);
			break;
		default:
			index = va_arg(args, int);
			break;
	}

	if (index == 0)
	{
		if (flag == '+' || flag == ' ')
		{
			my_putchar(flag);
			counter++;
		}
		my_putchar('0');
		return (counter + 1);
	}

	if (index == LONG_MIN)
	{
		my_putchar('-');
		my_putchar('9');
		p_integer(223372036854775808, &counter, flag, 0);
		counter += 2;
		return (counter);
	}

	p_integer(index, &counter, flag, 1);

	return (counter);
}

