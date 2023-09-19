#include "main.h"
/**
 * _isdigit - checks if character is digit
 * @c: character to check
 * Return: 1 or 0
 */
int _isdigit(int c)
{
return (c >= '0' && c <= '9');
}
/**
 * _strlen - returns the length of a string
 * @s: string its length to check
 * Return: integer length of string
 */
int _strlen(char *s)
{
int i = 0;

while (*s++)
i++;
return (i);
}
/**
 * print_num - prints a number with options
 * @str: the base number as a string
 * @params: parameter
 * Return: chars printed
 */
int print_num(char *str, my_parameters *params)
{
unsigned int index = _strlen(str);
int negative = (!params->flag_unsign && *str == '-');

if (!params->spec_precision && *str == '0' && !str[1])
{
str = "";
}
if (negative)
{
str++;
index--;
}
if (params->spec_precision != UINT_MAX)
while (index++ < params->spec_precision)
*--str = '0';
if (negative)
{
*--str = '-';
}
if (!params->flag_minus)
{
return (print_right(str, params));
}
else
{
return (print_left(str, params));
}
}

/**
 * print_right - prints a number with options
 * @str: the base number as a string
 * @params: parameter
 * Return: num of chars
 */
int print_right(char *str, my_parameters *params)
{
unsigned int n = 0, index = _strlen(str);
char pad_char = ' ';
unsigned int negative, negative2;

if (params->flag_zero && !params->flag_minus)
{
pad_char = '0'; }
negative = negative2 = (!params->flag_unsign && *str == '-');
if (negative && index < params->spec_width && pad_char == '0'
&& !params->flag_minus)
{
str++; }
else
{
negative = 0; }
if ((params->flag_plus && !negative2) ||
(!params->flag_plus && params->flag_space && !negative2))
{ index++; }
if (negative && pad_char == '0')
n = n + my_putchar('-');
if (params->flag_plus && !negative2 && pad_char == '0' && !params->flag_unsign)
n = n + my_putchar('+');
else if (!params->flag_plus && params->flag_space && !negative2 &&
!params->flag_unsign && params->flag_zero)
n = n + my_putchar(' ');
while (index++ < params->spec_width)
n = n + my_putchar(pad_char);
if (negative && pad_char == ' ')
n = n + my_putchar('-');
if (params->flag_plus && !negative2 && pad_char == ' ' && !params->flag_unsign)
n = n + my_putchar('+');
else if (!params->flag_plus && params->flag_space && !negative2 &&
!params->flag_unsign && !params->flag_zero)
n = n + my_putchar(' ');
n = n + my_puts(str);
return (n);
}

/**
 * print_left - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 * Return: chars
 */
int print_left(char *str, my_parameters *params)
{
unsigned int num = 0, i = _strlen(str);
unsigned int neg1, neg2;
char pad_char = ' ';

if (params->flag_zero && !params->flag_minus)
pad_char = '0';
neg1 = neg2 = (!params->flag_unsign && *str == '-');
if (neg1 && i < params->spec_width && pad_char == '0' && !params->flag_minus)
str++;
else
neg1 = 0;

if (params->flag_plus && !neg2 && !params->flag_unsign)
{
num = num + my_putchar('+'), i++;
}
else if (params->flag_space && !neg2 && !params->flag_unsign)
{
num = num + my_putchar(' '), i++;
}
num += my_puts(str);
while (i++ < params->spec_width)
{
num += my_putchar(pad_char); }
return (num);
}
