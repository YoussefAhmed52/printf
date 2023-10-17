#include "main.h"

/**
 * _isdigit - see if character is digit
 * @c: checked character
 * Return: 1 if digit, 0 if not
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 *_strlen - return length of the string
 * @s: the string
 * Return: length of the string
 */

int _strlen(char *s)
{
	int j = 0;

	while (*s++)
		j++;
	return (j);
}

/**
 * print_number - prints a number
 * @str: the base of the string
 * @params: struct parameters
 * Return: printed chars
 */

int print_number(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number
 * @str: base as a string
 * @params: struct parameters
 * Return: printed chars
 */

int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (!params->minus_flag && params->zero_flag)
		pad_char = '0';
	neg = neg2 = (*str == '-' && !params->unsign);
	if (neg && !params->minus_flag && i < params->width && pad_char == '0')
		str++;
	else
		neg = 0;
	if ((!neg2 && params->plus_flag) ||
			(params->space_flag && !params->plus_flag && !neg2))
		i++;
	if (pad_char == '0' && neg)
		n += _putchar('-');
	if (!neg2 && pad_char == '0' && !params->unsign && params->plus_flag)
		n += _putchar('+');
	else if (!neg && params->space_flag &&
			!params->plus_flag && !params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (!neg2 && pad_char == ' ' && !params->unsign && params->plus_flag)
		n += _putchar('+');
	else if ((!neg2 && params->space_flag && !params->plus_flag &&
				!params->unsign && !params->zero_flag))
		n += _putchar(' ');

	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - prints a number
 * @str: base as a string
 * @params: struct parameters
 * Return: printed chars
 */

int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, j = _strlen(str);
	char pad_char = ' ';

	if (!params->minus_flag && params->zero_flag)
		pad_char = '0';
	neg = neg2 = (*str == '-' && !params->unsign);
	if (neg && !params->minus_flag && i < params->width && pad_char == '0')
		str++;
	else
		neg = 0;


	if (!neg2 && !params->unsign && params->plus_flag)
		n += _putchar('+'), j++;
	else if (!neg2 && params->space_flag && !params->unsign)
		n += _putchar(' '), j++;
	n += _puts(str);
	while (j++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
