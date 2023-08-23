#include &quot;main.h&quot;
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{&#39;c&#39;, print_char}, {&#39;s&#39;, print_string}, {&#39;%&#39;, print_percent},
		{&#39;i&#39;, print_int}, {&#39;d&#39;, print_int}, {&#39;b&#39;, print_binary},
		{&#39;u&#39;, print_unsigned}, {&#39;o&#39;, print_octal}, {&#39;x&#39;, print_hexadecimal},
		{&#39;X&#39;, print_hexa_upper}, {&#39;p&#39;, print_pointer}, {&#39;S&#39;, print_non_printable},
		{&#39;r&#39;, print_reverse}, {&#39;R&#39;, print_rot13string}, {&#39;\0&#39;, NULL}
	};
	for (i = 0; fmt_types[i].fmt != &#39;\0&#39;; i++)

		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == &#39;\0&#39;)
	{
		if (fmt[*ind] == &#39;\0&#39;)
			return (-1);
		unknow_len += write(1, &quot;%%&quot;, 1);
		if (fmt[*ind - 1] == &#39; &#39;)
			unknow_len += write(1, &quot; &quot;, 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != &#39; &#39; &amp;&amp; fmt[*ind] != &#39;%&#39;)
				--(*ind);
			if (fmt[*ind] == &#39; &#39;)
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &amp;fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
