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

switch (specifier)
{
case 'c':
counter = counter + my_char(args);
break;
case 's':
counter = counter + my_string(args);
break;
case '%':
counter = counter + my_putchar('%');
break;
case 'd':
case 'i':
counter = counter + my_integer(args, flag, length);
break;
default:
counter = counter + your_specifier(specifier, args, flag, length);
break;
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

switch (specifier)
{
case 'b':
counter = counter + my_binary(args);
break;
case 'u':
counter = counter + my_unsign_int(args, length);
break;
case 'o':
counter = counter + octal(args, flag, length);
break;
case 'x':
counter = counter + hex_low(args, flag, length);
break;
case 'X':
counter = counter + hex_up(args, flag, length);
break;
case 'S':
counter = counter + custom_s(args);
break;
case 'p':
counter = counter + my_pointer(args);
break;
default:
counter = counter + my_putchar('%');
counter = counter + my_putchar(specifier);
break;
}

return (counter);
}
