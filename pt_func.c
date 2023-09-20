#include "main.h"

/**
 * its_put - writes the character x stdout.
 * @x: The character to print
 * Return: 1(success)
 * On error, -1 is returned, and errno is set appropriately.
 */
int its_put(char x)
{
	return (write(1, &x, 1));
}


/**
 * pt_char - print a character.
 * @args: argument
 * Return: no characters printed
 */
int pt_char(va_list args)
{
	its_put(va_arg(args, int));
	return (1);
}

/**
 * pt_string - prints a string
 * @args: argument
 * Return: no of string characters printed
 */
int pt_string(va_list args)
{
	char *s;
	int no_chars = 0;

	s = va_arg(args, char*);

	if (s == NULL)
		s = "(null)";

	while (*s != '\0')
	{
		its_put(*s);
		s++;
		no_chars++;
	}
	return (no_chars);
}

/**
 * pt_percent - print a percentage
 * @args: argument.
 * Return: (1) % character printed
 */
int pt_percent(va_list args)
{
	(void)args;
	its_put('%');
	return (1);
}

/**
 * pt_int - print a integers unsigned and signed.
 * @args: argument
 *
 * Return: no of integer digits printed
 */
int pt_int(va_list args)
{
	unsigned int num;
	int arg;
	int no_digit = 0;
	int divisor = 1;
	char n;

	arg = va_arg(args, int);
	if (arg == 0)
	{
		n = '0';
		its_put(n);
		return (1);
	}
	if (arg < 0)
	{
		n = '-';
		its_put(n);
		no_digit = 1;
		num = arg * -1;
	}
	else
		num = arg;

	while ((num / divisor) >= 10)
		divisor *= 10;

	while (divisor != 0)
	{
		n = '0' + (num / divisor);
		its_put(n);
		no_digit++;

		num %= divisor;
		divisor /= 10;
	}

	return (no_digit);
}
