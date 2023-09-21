#include "main.h"

/**
 * rev - printing reverse
 *
 * @args: string
 *
 * Return: number bytes printed
 */
int rev(va_list args)
{
int len, sum = 0;
char *str = va_arg(args, char *);
(void)args;

if (str)
{
for (len = 0; *str; str++)
len++;
str--;
for (; len > 0; len--, str--)
sum +=  my_string("%r",str);
}
return (sum);
}
