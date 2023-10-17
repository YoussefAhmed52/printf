#include "main.h"

/**
 * print_hex - prints hex numbers unsigned and lowercase
 * @ap: pointer arguments
 * @params: struct parameters
 * Return: printed bytes
 */

int print_hex(va_list ap, params_t *params)
{
	char *str;
	unsigned long l;
	int c = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(1, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (l && params->hashtag_flag)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}


/**
 * print_HEX - prints hex numbers unsigned and lowercase
 * @ap: pointer arguments
 * @params: struct parameters
 * Return: printed bytes
 */

int print_HEX(va_list ap, params_t *params)
{
	int c = 0;
	char *str;
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(1, 16, CONVERT_UNSIGNED, params);
	if (l && params->hashtag_flag)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_binary - print binary number unsigned
 * @params: struct params
 * @ap: pointer arguments
 * Return: printed bytes
 */

int print_binary(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (n && params->hashtag_flag)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_octal - print octal number unsigned
 * @params: struct params
 * @ap: pointer arguments
 * Return: printed bytes
 */

int print_octal(va_list ap, params_t *params)
{
	int c = 0;
	unsigned long l;
	char *str;


	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(1, 8, CONVERT_UNSIGNED, params);
	if (l && params->hashtag_flag)
	{
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}
