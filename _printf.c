#include "main.h"

/**
 * _printf - a function that prints anything
 * @format: format
 * Return: num of bytes
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list str;
	char *p, *start;
	my_parameters params = f_par;

	va_start(str, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		first_parameters(&params, str);
		if (*p != '%')
		{
			sum += my_putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (obtain_flag(p, &params)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = obtain_width(p, &params, str);
		p = obtain_precision(p, &params, str);
		if (obtain_modifier(p, &params))
			p++;
		if (!obtain_specifier(p))
			sum += range_print(start, p,
				params.long_mod || params.short_mod ? p - 1 : 0);
		else
			sum += obtain_print(p, str, &params);
	}
	my_putchar(flush);
	va_end(str);
	return (sum);
}
