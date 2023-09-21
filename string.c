#include "main.h"
/**
* custom_s - a function to s handle
* @args: arguments
* Return: num of chars
*/
int custom_s(va_list args)
{
char *ptr = va_arg(args, char *);
int counter = 0;
int index;
char flags = '\0';

if (ptr == NULL)
ptr = "(null)";

for (index = 0; ptr[index] != '\0'; index++)
{
if ((ptr[index] > 0 && ptr[index] < 32) || ptr[index] >= 127)
{
counter = counter + print_hex(ptr[index], flags);
}
else
{
my_putchar(ptr[index]);
counter++;
}
}
return (counter);
}

/**
* print_hex - a function that rints an hexadecimal value
* @c: hex char
* @flag: The flag character
* Return: num of chars
*/
int print_hex(unsigned char c, char flag)
{
char hex_digit[] = "0123456789ABCDEF";
int counter = 0;

(void)flag;
my_putchar('\\');
my_putchar('x');
my_putchar(hex_digit[(c >> 4) & 0xF]);
my_putchar(hex_digit[c & 0xF]);

counter = counter + 4;

return (counter);
}
