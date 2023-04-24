#include"main.h"
void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - function that produces
 * output according to a format
 * @format: character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int j, outputted = 0, outputted_chars = 0;
	int flags, width, precision, size, buff_ind = 0;

	va_list list;

	char buffer(buff_size);
	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (j = 0; format && format[j] != '\0'; j++)
	{
		if (format[j] != '\0')
		{
			buffer[buff_ind++] = format[j];
			if (buff_ind == buff_size)
				print_buffer(buffer, &buff_ind);
			outputted_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &j);
			width = get_width(format, &j, list)
			precision = get_precision(format, &j, list);
			size = get_size(format, &j)
			j++;
			outputted = handle_print(format, &j, list, buffer,
			flags, width, precision, size);
			if (outputted == -1)
				return (-1);
			outputted_chars += outputted;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (outputted_chars);
}

/**
 * print_buffer - prints the contents of the buffer
 * @buffer: Array of characters
 * @buff_ind: The index to add the next char
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff _ind = 0;
}
