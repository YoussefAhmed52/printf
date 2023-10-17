#include "main.h"
/**
 * print_char - print character
 * @params: struct parameters
 * @ap: pointer arguments
 * Return: number of printed chars
 */

int print_char(va_list ap, params_t *params)
{
	unsigned int pad = 1, ch = va_arg(ap, int), sum = 0;
	char pad_char = ' ';

	if (params->minus_flag)
	{
		sum += _putchar(ch);
	}
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
	{
		sum += _putchar(ch);
	}
	return (sum);
}

/**
 * print_int - print integers
 * @params: struct parameter
 * @ap: pointer arguments
 * Return: printed integers
 */

int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
	{
		l = va_arg(ap, long);
	}
	else if (params->h_modifier)
	{
		l = (short int)va_arg(ap, int);
	}
	else
	l = (int)va_arg(ap, int);

	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - print strings
 * @params: struct parameter
 * @ap: pointer arguments
 * Return: printed integers
 */

int print_string(va_list ap, params_t *params)
{
	unsigned int sum = 0, i = 0, j, pad = 0;
	char *str = va_arg(ap, char *), pad_char = ' ';

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
		{
			for (i = 0; i < pad; i++)
			{
				sum += _putchar(*str++);
			}
		}
		else
			sum += _puts(str);
	}
	while (j++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
		{
			for (i = 0; i < pad; i++)
			{
				sum += _putchar(*str++);
			}
		}
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - print percent
 * @params: struct parameter
 * @ap: pointers arguments
 * Return: percent
 */

int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - format specifier
 * @params: struct parameter
 * @ap: pointer arguments
 * Return: specifier
 */

int print_S(va_list ap, params_t *params)
{
	char *hex;
	int sum = 0;
	char *str = va_arg(ap, char *);

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if (*str >= 127 || (*str > 0 && *str < 32))
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
			sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
