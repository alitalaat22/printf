#include "main.h"
/**
*hex_low - a function to %x handle
*@args: arguments
*@flag: flag character
*@length: length modifier
*Return: num of chars
*/
int hex_low(va_list args, char flag, char length)
{
unsigned long int n_long;
unsigned short int n_short;
unsigned int n;

if (length == 'l')
{
n_long = va_arg(args, unsigned long int);
return (long_hex(n_long, 0, flag));
}
else if (length == 'h')
{
n_short = (unsigned short int)va_arg(args, unsigned int);
return (short_hex(n_short, 0, flag));
}
else
{
n = va_arg(args, unsigned int);
return (my_hex(n, 0, flag));
}
}
/**
*hex_up - a function to %x handle
*@args: arguments
*@flag: flag character
*@length: length modifier
*Return: num of chars
*/
int hex_up(va_list args, char flag, char length)
{
unsigned long int n_long;
unsigned short int n_short;
unsigned int n;

if (length == 'l')
{
n_long = va_arg(args, unsigned long int);
return (long_hex(n_long, 1, flag));
}
else if (length == 'h')
{
n_short = (unsigned short int)va_arg(args, unsigned int);
return (short_hex(n_short, 1, flag));
}
else
{
n = va_arg(args, unsigned int);
return (my_hex(n, 1, flag));
}
}

/**
*my_hex - a function that prints an unsigned int hex
*@num: unsigned integer
*@upper: 0 for lowercase letters, 1 for uppercase letters
*@flag: flag character
*Return: num of chars
*/
int my_hex(unsigned int num, int upper, char flag)
{
unsigned int index = num;
int counter = 0;
char p = upper ? 'A' - 10 : 'a' - 10;

if (flag == '#')
{
my_putchar('0');
my_putchar(upper ? 'X' : 'x');
counter = counter + 2;
}

if (index / 16)
{
counter = counter + my_hex(index / 16, upper, '\0');
}
counter = counter + my_putchar((index % 16) < 10 ?
(index % 16) + '0' : (index % 16) + p);

return (counter);
}

/**
*long_hex - a function that prints an unsigned long integer hex
*@num: unsigned long integer
*@upper: 0 for lowercase letters, 1 for uppercase letters
*@flag: flag character
*Return: num of chars
*/
int long_hex(unsigned long int num, int upper, char flag)
{
unsigned long int index = num;
int counter = 0;
char p = upper ? 'A' - 10 : 'a' - 10;

if (flag == '#')
{
my_putchar('0');
my_putchar(upper ? 'X' : 'x');
counter = counter + 2;
}

if (index / 16)
{
counter = counter + long_hex(index / 16, upper, '\0');
}
counter = counter + my_putchar((index % 16) < 10 ?
(index % 16) + '0' : (index % 16) + p);

return (counter);
}

/**
*short_hex - a function that prints an unsigned short integer hex
*@num: unsigned short integer
*@upper: 0 for lowercase letters, 1 for uppercase letters
*@flag: The flag character
*Return: num of chars
*/
int short_hex(unsigned short int num, int upper, char flag)
{
unsigned short int index = num;
int counter = 0;
char p = upper ? 'A' - 10 : 'a' - 10;

if (flag == '#')
{
my_putchar('0');
my_putchar(upper ? 'X' : 'x');
counter = counter + 2;
}
if (index / 16)
{
counter = counter + short_hex(index / 16, upper, '\0');
}
counter = counter + my_putchar((index % 16) < 10 ?
(index % 16) + '0' : (index % 16) + p);

return (counter);
}
