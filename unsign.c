#include"main.h"
/**
* my_unsign_int - a function to u handle
* @args: arguments
* @length: length modifier
* Return: num of chars
*/
int my_unsign_int(va_list args, char length)
{
unsigned long int n_long;
unsigned short int n_short;
unsigned int num;

if (length == 'l')
{
long_n = va_arg(args, unsigned long int);
return (my_long_octal(long_n, flag));
}
else if (length == 'h')
{
short_n = (unsigned short int)va_arg(args, unsigned int);
return (my_short_octal(short_n, flag));
}
else
{
num = va_arg(args, unsigned int);
return (my_octal(num, flag));
}
}
/**
* print_unsigned_int - a function that prints an unsigned integer
* @num: unsigned int
* Return: num of chars
*/
int print_unsigned_int(unsigned int num)
{
unsigned int index = num;
int counter = 0;

if (index / 10)
{
counter = counter + print_unsigned_int(index / 10);
}
counter = counter + my_putchar((index % 10) + '0');

return (counter);
}

/**
* print_unsigned_long - a function that prints an unsigned long int
* @num_l: unsigned long int
* Return: num of chars
*/
int print_unsigned_long(unsigned long int num_l)
{
unsigned long int index = num_l;
int counter = 0;

if (index / 10)
{
counter = counter + print_unsigned_long(index / 10);
}
counter = counter + my_putchar((index % 10) + '0');

return (counter);
}

/**
* print_unsigned_short - a function that prints an unsigned short int
* @num_h: unsigned short int
* Return: num of chars
*/
int print_unsigned_short(unsigned short int num_h)
{
unsigned short int index = num_h;
int counter = 0;

if (index / 10)
{
counter = counter + print_unsigned_short(index / 10);
}
counter = counter + my_putchar((index % 10) + '0');

return (counter);
}
