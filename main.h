#ifndef _PRINTF_H
#define _PRINTF_H



#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_UNSIGNED 2
#define CONVERT_LOWERCASE 1

/**
 * struct parameters - struct parameter
 * @unsign: flag if unsigned val
 * @plus_flag: if plus_flag is specified it will be on
 * @space_flag: if hashtag_flag is specified it will be on
 * @minus_flag: if _flag is specified it will be on
 * @hashtag_flag: if _flag specified it will be on
 * @zero_flag: if _flag specified it will be on
 * @width: field width specified
 * @precision: field precision specified
 * @l_modifier: if l_modifier is specified it will be on
 * @h_modifier: if h_modifier is specified it will be on
 */

typedef struct parameters
{
	unsigned int unsign     : 1;
	unsigned int minus_flag     : 1;
	unsigned int zero_flag     : 1;
	unsigned int space_flag     : 1;
	unsigned int hashtag_flag     : 1;
	unsigned int plus_flag     : 1;

	unsigned int precision     : 1;
	unsigned int width     : 1;

	unsigned int l_modifier     : 1;
	unsigned int h_modifier     : 1;

} params_t;


/**
 * struct specifier - token struct
 * @specifier: token format
 * @f: the associated function
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);

/* number.c */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* specifier.c */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_modifier(char *s, params_t *params);
int *get_width(char *s, params_t *params, va_list ap);
int get_flag(char *s, params_t *params);

/* convert_number.c */
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);
int print_hex(va_list ap, params_t *params);

/* simple_printers.c */
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);
int print_from_to(char *start, char *stop, char *except);



/* print_numbers.c */
int print_number(char *tr, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_numbers_left_shift(char *str, params_t *params);
int _isdigit(int c);
int _strlen(char *s);


/* params.c */
void init_params(params_t *params, va_list ap);

/* string_fields.c */
char *get_precision(char *p, params_t *params, va_list ap);

/* _printf.c */
int _printf(const char *format, ...);

#endif

