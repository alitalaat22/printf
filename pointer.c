#include "main.h"
/**
* my_pointer - a function to p handle
* @args: arguments
* Return: num of chars
*/
int my_pointer(va_list args)
{
void *str = va_arg(args, void *);
uintptr_t add = (uintptr_t)str;
int counter = 0, jar;
char hex_buff[16];
int index = 0;
char *ptr;

if (str == NULL)
{
ptr = "(nil)";
for (jar = 0; ptr[jar] != '\0'; jar++)
{
counter = counter + my_putchar(ptr[jar]);
}
return (counter);
}

counter = counter + my_putchar('0');
counter = counter + my_putchar('x');
while (add > 0)
{
int remain = add % 16;

if (remain < 10)
{
hex_buff[index++] = '0' + remain;
}
else
{
hex_buff[index++] = 'a' + (remain - 10);
}
add = add / 16;
}
for (jar = index - 1; jar >= 0; jar--)
{
counter = counter + my_putchar(hex_buff[jar]);
}
return (counter);
}
