#include "main.h"

/**
 * _printf - a function that prints anything
 * @format: format
 * Return: num of bytes
 */
int _printf(const char *format, ...)
{
int result = 0;
va_list str;
char *ptr;
char *begin;

my_parameters params = f_par;

va_start(str, format);
/* test cases */
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (ptr = (char *)format; *ptr; ptr++)
{
first_parameters(&params, str);
if (*ptr != '%')
{
result += my_putchar(*ptr);
continue;
}
begin = ptr;
ptr++;
while (obtain_flag(ptr, &params)) /* check if flag */
{
ptr++;/* move to next character */
}
ptr = obtain_width(ptr, &params, str);
ptr = obtain_precision(ptr, &params, str);
if (obtain_modifier(ptr, &params))
ptr++;
if (!obtain_specifier(ptr))
{ result += range_print(begin, ptr,
params.long_mod || params.short_mod ? ptr - 1 : 0); }
else
result += obtain_print(ptr, str, &params);
}
my_putchar(flush);
va_end(str);
return (result);
}
