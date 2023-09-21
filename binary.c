#include "main.h"

/**
* my_binary - a function to b handle
* @args: Arguments
* Return: num of chars
*/
int my_binary(va_list args)
{
unsigned int n = va_arg(args, unsigned int);
int count = 0;
unsigned int masker = 1u << 31;

while ((masker & n) == 0 && masker != 0)
{
masker >>= 1;
}

while (masker != 0)
{
if ((n & masker) == 0)
{
count = count + my_putchar('0');
}
else
{
count = count + my_putchar('1');
}
masker >>= 1;
}

if (count == 0)
{
count += my_putchar('0');
}
return (count);
}
