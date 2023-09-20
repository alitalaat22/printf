#include "main.h"

/**
 * func_spec - selects the correct function
 * @x: specifier letter
 * Return: int pointer to correct operation
*/
int (*func_spec(char x))(va_list args)
{
	int y = 0;
	specifier_t specifier[] = {
		{'c', pt_char},
		{'s', pt_string},
		{'%', pt_percent},
		{'d', pt_int},
		{'p', pt_pointer},
		{'i', pt_int},
		{'b', pt_binary},
		{'\0', NULL}
	};
	while (specifier[y].letter != '\0')
	{
		if (x == specifier[y].letter)
			return (specifier[y].func);
		y++;
	}
	return (NULL);
}


/**
 * _printf - custom printf
 * @format: character is string
 * Return: no. of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int y = 0;
	int counter = 0;
	int (*func_f)(va_list);

	if (!format || (format[y] == '%' && !format[y + 1]))
		return (-1);
	if (format[y] == '%' && format[y + 1] == ' ' && !format[y + 2])
		return (-1);
	va_start(args, format);
	while (format[y] != '\0')
	{
		if (format[y] != '%')
		{
			its_put(format[y]);
			counter++;
		}
		else if (format[y] == '%')
		{
			if (format[y + 1] == ' ')
				y++;
			func_f =func_spec(format[y + 1]);
			if (func_f)
			{
				counter += func_f(args);
				y++;
			}
			else
				its_put('%'), counter++;
		}
		else
		{
			its_put(format[y]);
			counter++;
		}
		y++;
	}
	va_end(args);
	return (counter);
}
