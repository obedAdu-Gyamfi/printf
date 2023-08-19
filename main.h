#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdarg.h>
#include <unistd.h>

/**Buffer**/
#define BUFFdSIZE 1024
#define UNUSED(x) (void)(x)

/**Flags**/
#define MINUS 1
#define PLUS 2
#define ZERO 4
#define HASH 8
#define SPACE 16
#define FLAG_LEFT (1 << 0)
#define FLAG_ZERO (1 << 1)

/**Sizes**/
#define LONG 2
#define SHORT 1


/**
 * struct fmt - Struct for character formats
 *
 * @fmt: The character format
 * @fn: The associated function of the format
 */
/*
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};
*/
/**
 * typedef struct fmt fmt_fn - Typedef Struct for character format
 *
 * @fmt: The character format
 * @fmt_fn: The associated function of the format
 */

/*typedef struct fmt fmt_fn;*/

/**Prototypes**/
int _printf(const char *format, ...);
/*int handle_print(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);*/


/**Char and String functions
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);

Numbers functions
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_char, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);

Unprintable character functions
int print_unprintable(va_list types, char buffer[], int flags, int width, int precision, int size);

Memory address functions
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);

Function for other specifiers
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

Function for reverse string
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);

Function for Rot13 string
int print_rot13(va_list types, char buffer[], int flags, int width, int precision, int size);

Functions for write function
int write_char(char c, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_positive, int index, char buffer[], int flags, int width, int precision, int size);
int write_num(int index, char buffer[], int flags, int width, int precision, int length, char padd, char extra_c);
int write_unsigned(int is_negative, int index, char buffer[], int flags, int width, int precision, int size);
int write_pointer(char buffer[], int index, int length, int width, int flags, char padd, char extra_c, int padd_start);

Other functions
int is_printable(char i);
int append_hexa(char i, char j[], int k);
int is_digit(char x);
long int convert_size_number(long int number, int size);
long int convert_size_unsigned(unsigned long int number, int size);

*/

/**
 * struct d_type - structure of my functions.
 * @sp: specifier to match functions
 * @f: function
 */
typedef struct d_type
{
	char *sp;
	int (*f)(va_list args);
} d_type;

int _print_char(va_list args);
int print_str(va_list args);
int _strlen(char *c);
int print_int(va_list args);
void binary(unsigned int, int *len);
int print_ui_b(va_list args);
int print_unsigned(va_list args);
int print_X(va_list X);
int print_x(va_list x);
int print_rot(va_list args);
int identify(char c, va_list);
int print_hex(unsigned int n, unsigned int c);
int _putchar (char c);
int print_oct(unsigned int n);
#endif
