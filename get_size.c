#include <main.h>
/**
 * get_size - Calculates the size to cast an argument
 * @format: Formatted string  to print the arguments
 * @i: List of arguments to be printed
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == &#39;l&#39;)
		size = S_LONG;
	else if (format[curr_i] == &#39;h&#39;)
		size = S_SHORT;
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;
	return (size);
}
