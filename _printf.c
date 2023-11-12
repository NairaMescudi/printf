#include "main.h"

/**
  * _printf - prints to stdout
  * @format: Specifies the format to print
  * @...: Variadic arguments
  *
  * Return: Number of chars printed.
  */
int _printf(const char *format, ...)
{
	int char_count = 0, fmt_status;
	va_list ap;

	if (!(*format))
		return (char_count);
	fmt_status = parse_format(format);

	if (fmt_status == 1)
	{
		va_start(ap, format);
		while (*format)
		{
			if (*format == '%')
				char_count += p_func(ap, *++format);
			else
				char_count += write(1, format, 1);
			++format;
		}
		va_end(ap);
	}
	return (char_count);
}

/**
  * p_func - Auxilliary Function
  * Description: It calls other print functions based on the specifier
  * @ap: Argument Pointer
  * @specifier: Format Specifier Character
  * Return: Number of chars printed
  */
int p_func(va_list ap, char specifier)
{
	int char_count = 0;

	switch (specifier)
	{
		case 'c':
			char_count += print_char(ap);
			break;
		case 's':
			char_count += print_string(ap);
			break;
		case '%':
			char_count += write(1, "%", 1);
			break;
	return (char_count);
}