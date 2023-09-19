#include "main.h"
/**
 * p_add - prints address
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int p_add(va_list ap, my_parameters *params)
{
unsigned long int num = va_arg(ap, unsigned long int);
char *str;

if (!num)
{
return (my_puts("(nil)"));
}
str = convert(num, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
*--str = 'x';
*--str = '0';
return (print_num(str, params));
}

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @params: paramater struct
 * Return: string
 */
char *convert(long int num, int base, int flags, my_parameters *params)
{
static char *array, buff[50];
char signer = 0;
char *ptr;
unsigned long n = num;
/* to avoid not using it */
(void)params;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
signer = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buff[49];
*ptr = '\0';

do {
*--ptr = array[n % base];
n /= base;
} while (n != 0);
if (signer)
{
*--ptr = signer;
}
return (ptr);
}

/**
 * p_unsigned - prints unsigned integer numbers
 * @ap: argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 */
int p_unsigned(va_list ap, my_parameters *params)
{
unsigned long index;

if (params->long_mod)
{
index = (unsigned long)va_arg(ap, unsigned long);
}
else if (params->short_mod)
{
index = (unsigned short int)va_arg(ap, unsigned int);
}
else
{
index = (unsigned int)va_arg(ap, unsigned int);
}
params->flag_unsign = 1;
return (print_num(convert(index, 10, CONVERT_UNSIGNED, params), params));
}
