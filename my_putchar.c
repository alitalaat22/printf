#include <unistd.h>
/**
 * my_putchar - Function prints char
 * @s: Char to printer
 * Return: Character
 */
int my_putchar(char s)
{
return (write(1, &s, 1));
}
