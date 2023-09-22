#include "main.h"
/**
* my_binary - a function to b handle
* @args: Arguments
* Return: num of chars
*/
int my_binary(va_list args)
{
int counter = 0;
unsigned int num = va_arg(args, unsigned int);
unsigned int masker = 1u << 31;

while ((masker & num) == 0 && masker != 0)
{
masker >>= 1;
}

while (masker != 0)
{
if ((num & masker) == 0)
{
counter = counter + my_putchar('0');
}
else
{
counter = counter + my_putchar('1');
}
masker >>= 1;
}

if (counter == 0)
{
counter = counter + my_putchar('0');
}
return (counter);
}
