#include "main.h"
/**
*p_integer - a function that prints with recursion
*@num: int
*@counter: pointer to sum of chars
*@flag: plus or ' '
*@start: 1 or 0
*/
void p_integer(long int num, int *counter, char flag, int start)
{
if (start)
{
if (num < 0)
{
my_putchar('-');
(*counter)++;
num = -num;
}
else if (flag == '+' || flag == ' ')
{
my_putchar(flag);
(*counter)++;
}
}
if (num / 10)
{
p_integer(num / 10, counter, flag, 0);
}
my_putchar('0' + (num % 10));
(*counter)++;
}

/**
*my_integer - a function to i and d handle
*@args: arguments
*@flag: flag character
*@length: length char
*Return: num of char
*/
int my_integer(va_list args, char flag, char length)
{
long int index;
int counter = 0;

if (length == 'l')
{
index = va_arg(args, long int);
}
else if (length == 'h')
{
index = (short int)va_arg(args, int);
}
else
{
index = va_arg(args, int);
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
counter = counter + 2;
return (counter);
}
p_integer(index, &counter, flag, 1);

return (counter);
}

