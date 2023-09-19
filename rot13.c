#include "main.h"
/**
 * rot13_ch - a function that prints string in rot13
 * @ptr: a pointer to string
 * @p: parameters
 * Return: sum of bytes
 */
int rot13_ch(va_list ptr, my_parameters *p)
{
int char_index, rot13_index;
int sum = 0;
char rot13_array[] =
"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
char *string = va_arg(ptr, char *);

(void)p;

char_index = 0;
rot13_index = 0;

while (string[char_index])
{
if ((string[char_index] >= 'A' && string[char_index] <= 'Z')
|| (string[char_index] >= 'a' && string[char_index] <= 'z'))
{
rot13_index = string[char_index] - 65;
sum = sum + my_putchar(rot13_array[rot13_index]);
}
else
{
sum = sum + my_putchar(string[char_index]);
}
char_index++;
}
return (sum);
}
