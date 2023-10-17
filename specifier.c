#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: string format
 * Return: bytes printed
 */

int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
		};

	int j = 0;

	while (specifiers[j].specifier)
	{
		if (*s == specifiers[j].specifier[0])
		{
			return (specifiers[j].f);
		}
		j++;
	}
	return (NULL);
}

/**
 * get_print_func -finds func format
 * @s: string format
 * @ap: pointer arguments
 * @params: struct parameters
 * Return: bytes printed
 */

int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - finds func flag
 * @s: string format
 * @params: struct parameters
 * Return: if flag was valid
 */

int get_flag(char *s, params_t *params)
{
	int e = 0;

	switch (*s)
	{
		case '#':
			e = params->hashtag_flag = 1;
			break;
		case '-':
			e = params->minus_flag = 1;
			break;
		case ' ':
			e = params->space_flag = 1;
			break;
		case '+':
			e = params->plus_flag = 1;
			break;
		case '0':
			e = params->zero_flag = 1;
			break;
	}
	return (e);
}

/**
 * get_modifier - finds func modifier
 * @s: string format
 * @params: struct parameters
 * Return: if modifier was valid
 */

int get_modifier(char *s, params_t *params)
{
	int e = 0;

	switch (*s)
	{
		case 'h':
			e = params->h_modifier = 1;
			break;
		case 'l':
			e = params->l_modifier = 1;
			break;
	}
	return (e);
}

/**
 * get_width - get the width from format string
 * @s: string format
 * @params: struct parameters
 * @ap: pointer arguments
 * Return: new pointer
 */

int *get_width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
