#include "main.h"
/**
* my_specifier - a function of conversion specifiers handle
* @specifier: conversion specifier character
* @args: arguments
* @flag: flag character
* @length: The length of char
* Return: Count of chars
*/
int my_specifier(char specifier, va_list args, char flag, char length)
{
int counter = 0;

if (specifier == 'c')
{
counter = counter + my_char(args);
}
else if (specifier == 's')
{
counter = counter + my_string(args);
}
else if (specifier == '%')
{
counter = counter + my_putchar('%');
}
else if (specifier == 'd' || specifier == 'i')
{
counter = counter + my_integer(args, flag, length);
}
else
{
counter = counter + your_specifier(specifier, args, flag, length);
}

return (counter);
}

/**
* your_specifier - a function & extra conversion
* @specifier: conversion specifier
* @args: arguments
* @flag: flag character
* @length: length of character
* Return: sum of chars
*/
int your_specifier(char specifier, va_list args, char flag, char length)
{
int counter = 0;

if (specifier == 'b')
{
counter = counter + my_binary(args); }
else if (specifier == 'u')
{
counter = counter + my_unsign_int(args, length); }
else if (specifier == 'o')
{
counter = counter + octal(args, flag, length); }
else if (specifier == 'x')
{
counter = counter + hex_low(args, flag, length); }
else if (specifier == 'X')
{
counter = counter + hex_up(args, flag, length); }
else if (specifier == 'S')
{
counter = counter + custom_s(args); }
else if (specifier == 'R')
{
counter = counter + rot13_ch(args); }
else if (specifier == 'p')
{
counter = counter + my_pointer(args);
}
else
{
counter = counter + my_putchar('%');
counter = counter + my_putchar(specifier);
}

return (counter);
}
