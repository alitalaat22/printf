#include "main.h"
/**
* custom_s - a function to s handle
* @args: arguments
* Return: num of chars
*/
int custom_s(va_list args)
{
int counter = 0;
int index;
char flags = '\0';
char *ptr = va_arg(args, char *);

if (!ptr)
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
* @character: hex char
* @flags: flag character
* Return: num of chars
*/
int print_hex(unsigned char character, char flags)
{
int counter = 0;
char hex_digit[] = "0123456789ABCDEF";

(void)flags;
my_putchar('\\');
my_putchar('x');
my_putchar(hex_digit[(character >> 4) & 0xF]);
my_putchar(hex_digit[character & 0xF]);

counter = counter + 4;

return (counter);
}
