#include "main.h"

/**
*octal - a function to o handle
*@args: The arguments
*@flag: flag character
*@length: The length modifier
*Return: num of char printed
*/
int octal(va_list args, char flag, char length)
{
unsigned long int long_n;
unsigned short int short_n;
unsigned int num;

switch (length)
{
case 'l':
{
long_n = va_arg(args, unsigned long int);
return (my_long_octal(long_n, flag));
break;
}
case 'h':
{
short_n = (unsigned short int)va_arg(args, unsigned int);
return (my_short_octal(short_n, flag));
break;
}
default:
{
num = va_arg(args, unsigned int);
return (my_octal(num, flag));
break;
}
}

}
/**
*my_octal - Prints an unsigned int in octal
*@num: The unsigned integer to print
*@flag: flag character
*Return: num of chars printed
*/
int my_octal(unsigned int num, char flag)
{
unsigned int index = num;
int counter = 0;

if (flag == '#')
{
my_putchar('0');
counter++;
}

if (index / 8)
counter = counter + my_octal(index / 8, '\0');
counter = counter + my_putchar((index % 8) + '0');

return (counter);
}

/**
*my_long_octal - Prints an unsigned long int in octal
*@num_l: The unsigned long integer to print
*@flag: flag character
*Return: num of chars printed
*/
int my_long_octal(unsigned long int num_l, char flag)
{
unsigned long int index = num_l;
int counter = 0;

if (flag == '#')
{
my_putchar('0');
counter++;
}

if (index / 8)
counter = counter + my_long_octal(index / 8, '\0');
counter = counter + my_putchar((index % 8) + '0');

return (counter);
}

/**
*my_short_octal - Prints an unsigned short int in octal
*@num_h: The unsigned short integer to print
*@flag: flag character
*Return: number of chars printed
*/
int my_short_octal(unsigned short int num_h, char flag)
{
	unsigned short int index = num_h;
	int counter = 0;

	if (flag == '#')
	{
		my_putchar('0');
		counter++;
	}

	if (index / 8)
		counter = counter + my_short_octal(index / 8, '\0');
	counter = counter + my_putchar((index % 8) + '0');

	return (counter);
}
