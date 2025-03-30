/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:04:08 by gekido            #+#    #+#             */
/*   Updated: 2024/12/24 20:46:35 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	out_of_case(const char *format)
{
	write (1, &format[0], 1);
	write (1, &format[1], 1);
	return (2);
}

int	check_type(const char *format, va_list args)
{
	char	*str;

	if (format[0] == 'c')
		return (print_char(args));
	else if (format[0] == 's')
	{
		str = va_arg(args, char *);
		return (print_string(str));
	}
	else if (format[0] == 'p')
		return (print_pointer(args));
	else if (format[0] == 'd' || format[0] == 'i')
		return (print_number(args));
	else if (format[0] == 'u')
		return (print_unsigned(args));
	else if (format[0] == 'x')
		return (print_hex(args, 'x'));
	else if (format[0] == 'X')
		return (print_hex(args, 'X'));
	else if (format[0] == '%')
		return (print_percent());
	else
		return (out_of_case (format), 0);
}

int	ft_printf(const char *format, ...)
{
	size_t	count;
	va_list	args;
	int		len;

	va_start(args, format);
	count = 0;
	len = 0;
	while (format[count])
	{
		if (format[count] == '%')
		{
			count++;
			len += check_type(&format[count], args);
			count++;
		}
		else
		{
			write(1, &format[count], 1);
			count++;
			len++;
		}
	}
	return (va_end(args), len);
}
