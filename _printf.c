#include "main.h"
/**
 * _printf - a function to Custom implementation of printf
 * @format: format string
 * Return: sum of chars
 */
int _printf(const char *format, ...)
{
va_list args;
int counter = 0;
int result;

va_start(args, format);
if (format == NULL)
return (-1);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == '\0')
{
counter = -1;
break;
}
if (*format == ' ')
{
counter = -1;
break;
}
result = flag_and_specifier(&format, args, &counter);

if (result == -1)
{
counter = -1;
break;
}
}
else
{
counter = counter + my_putchar(*format);
}
format++;
}
va_end(args);
return (counter);
}

/**
 * flag_and_specifier - a function that handles the flag chars
 * @format: Ptr to current pos in string
 * @args: arguments
 * @count: Pointer to counter of chars
 * Return: 0 or -1
 */
int flag_and_specifier(const char **format, va_list args, int *count)
{
char flag = '\0';
char length = '\0';
int result;

if (**format == '+' || **format == ' ' || **format == '#')
{
flag = **format;
(*format)++;
}
else
{
flag = '\0';
}

if (**format == 'l' || **format == 'h')
{
length = **format;
(*format)++;
}
else
{
length = '\0';
}
result = my_specifier(**format, args, flag, length);
if (result == -1)
return (-1);
*count += result;
return (0);
}
