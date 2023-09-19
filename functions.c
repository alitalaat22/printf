#include "main.h"
/**
 * percent - prints string
 * @ptr: arguments
 * @params: parameters
 * Return: number chars printed
 */
int percent(va_list ptr, my_parameters *params)
{
/* these will be void to avoid not using them */
(void)params;
(void)ptr;

return (my_putchar('%'));
}

/**
 * print_character - a function that prints character
 * @ptr: arguments
 * @p: parameters
 * Return: sum of chars
 */
int print_character(va_list ptr, my_parameters *p)
{
char pad_of_char = ' ';
unsigned int index = 1;
unsigned int result = 0;
unsigned int character;

character = va_arg(ptr, int);
/* check flag_minus value */
if (p->flag_minus)
{
result = result + my_putchar(character);
}
while (index++ < p->spec_width)
{
result = result + my_putchar(pad_of_char);
}
if (!p->flag_minus)
{
result = result + my_putchar(character);
}
return (result);
}

/**
 * string - prints string
 * @ptr: arguments
 * @params: parameters
 * Return: num of chars
 */
int string(va_list ptr, my_parameters *params)
{
char *str, pad_of_char = ' ';
unsigned int counter = 0;
unsigned int result = 0, index = 0, jar;
/* to avoid usage of it */
(void)params;
str = va_arg(ptr, char *);

switch ((int)(!str))
case 1:
str = NULL_STRING;

jar = counter = _strlen(str);
if (params->spec_precision < counter)
{
jar = counter = params->spec_precision;
}
if (params->flag_minus)
{
if (params->spec_precision != UINT_MAX)
{
for (index = 0; index < counter; index++)
result = result + my_putchar(*str++);
}
else
result = result + my_puts(str);
}
while (jar++ < params->spec_width)
result = result + my_putchar(pad_of_char);
if (!params->flag_minus)
{
if (params->spec_precision != UINT_MAX)
{
for (index = 0; index < counter; index++)
result = result + my_putchar(*str++);
}
else
result = result + my_puts(str);
}
return (result);
}

/**
 * s_print - a function that custom format
 * @ptr: arguments
 * @params: parameters
 * Return: num of chars
 */
int s_print(va_list ptr, my_parameters *params)
{
char *str;
char *hexadecimal;
int result = 0;

str = va_arg(ptr, char *);
if ((int)(!str))
return (my_puts(NULL_STRING));
for (; *str; str++)
{
if ((*str > 0 && *str < 32) || *str >= 127)
{
result += my_putchar('\\');
result += my_putchar('x');
hexadecimal = convert(*str, 16, 0, params);
if (!hexadecimal[1])
{
result = result + my_putchar('0');
}
result = result + my_puts(hexadecimal);
}
else
{
result = result + my_putchar(*str);
}
}
return (result);
}
/**
 * print_integer - a function that prints integer
 * @ptr: argument
 * @p: parameters
 * Return: num of chars
 */
int print_integer(va_list ptr, my_parameters *p)
{
long index;
char *go;

if (p->long_mod)
index = va_arg(ptr, long);
else if (p->short_mod)
index = (short int)va_arg(ptr, int);
else
index = (int)va_arg(ptr,  int);
go = convert(index, 10, 0, p);
return (print_num(go, p));
}
