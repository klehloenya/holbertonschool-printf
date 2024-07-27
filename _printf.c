#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Return: number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
unsigned int i = 0, ibuf = 0;
va_list args;
char buffer[1024];

if (!format)
return (-1);

va_start(args, format);
while (format && format[i])
{
if (format[i] == '%')
{
i++;
if (format[i] == 'c')
ibuf = handl_buf(buffer, va_arg(args, int), ibuf);
else if (format[i] == 's')
ibuf = handle_string(buffer, va_arg(args, char *), ibuf);
else if (format[i] == '%')
ibuf = handl_buf(buffer, '%', ibuf);
else if (format[i] == 'd' || format[i] == 'i')
ibuf = handle_int(buffer, va_arg(args, int), ibuf);
else
ibuf = handl_buf(buffer, format[i], ibuf);
}
else
{
ibuf = handl_buf(buffer, format[i], ibuf);
}
i++;
}
write(1, buffer, ibuf);
va_end(args);
return (ibuf);
}

/**
 * handl_buf - adds character to buffer
 * @buf: buffer pointer
 * @c: character to add
 * @ibuf: index for buffer pointer
 * Return: new index for buffer pointer
 */
unsigned int handl_buf(char *buf, char c, unsigned int ibuf)
{
if (ibuf == 1024)
{
write(1, buf, ibuf);
ibuf = 0;
}
buf[ibuf] = c;
ibuf++;
return (ibuf);
}

/**
 * handle_string - adds a string to the buffer
 * @buf: buffer pointer
 * @str: string to add
 * @ibuf: index for buffer pointer
 * Return: new index for buffer pointer
 */
unsigned int handle_string(char *buf, char *str, unsigned int ibuf)
{
int i = 0;

while (str[i])
{
ibuf = handl_buf(buf, str[i], ibuf);
i++;
}
return (ibuf);
}
/**
 * handle_int - adds an integer to the buffer
 * @buf: buffer pointer
 * @num: integer to add
 * @ibuf: index for buffer pointer
 * Return: new index for buffer pointer
 */
unsigned int handle_int(char *buf, int num, unsigned int ibuf)
{
unsigned int temp, div = 1;
int i;

if (num < 0)
{
ibuf = handl_buf(buf, '-', ibuf);
num = -num;
}
temp = num;
while (temp > 9)
{
temp /= 10;
div *= 10;
}
for (i = 0; div > 0; div /= 10, i++)
{
ibuf = handl_buf(buf, ((num / div) % 10) + '0', ibuf);
}
return (ibuf);
}
