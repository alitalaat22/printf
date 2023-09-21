#include "main.h"

/**
 * _printf - a function to Custom implementation of printf
 * @format: the format string
 * Return: sum of chars
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
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
count = -1;
break;
}
if (*format == ' ')
{
count = -1;
break;
}
result = flag_and_specifier(&format, args, &count);

if (result == -1)
{
count = -1;
break;
}
}
else
{
count = count + my_putchar(*format);
}
format++;
}
va_end(args);
return (count);
}

/**
 * flag_and_specifier - function handles the flag chars
 * @format: Ptr to the current position in the format string
 * @args: arguments
 * @count: Pointer to the count of characters printed
 * Return: suc: 0 , error :-1
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
