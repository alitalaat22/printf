#include "main.h"

/**
 * rot13_ch - a function that prints string in rot13
 * @args: va_list argument
 * Return: sum of bytes
 */
int rot13_ch(va_list args)
{
int char_index = 0;
int rot13_index = 0;
int sum = 0;
char *string = va_arg(args, char *);
char rot13_array[] =
"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";

(void)args;

while (string[char_index])
{
if ((string[char_index] >= 'A' && string[char_index] <= 'Z')
|| (string[char_index] >= 'a' && string[char_index] <= 'z'))
{
rot13_index = string[char_index] - 65;
sum = sum + _printf("%c", rot13_array[rot13_index]);
}
else
{
sum = sum + _printf("%c", string[char_index]);
}
char_index++;
}
return (sum);
}
