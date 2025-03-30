/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:44:31 by gekido            #+#    #+#             */
/*   Updated: 2024/12/24 20:59:22 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (write (1, &c, 1), 1);
}

int	print_string(char *c)
{
	int		count;

	if (c == NULL)
		return (write (1, "(null)", 6), 6);
	count = 0;
	while (c[count])
	{
		write (1, &c[count], 1);
		count++;
	}
	return (count);
}

int	print_pointer(va_list args)
{
	void			*p;
	char			*str;
	int				len;

	p = va_arg(args, void *);
	if (!p)
		return (write(1, "(nil)", 5), 5);
	str = ft_utoa_base((unsigned long) p, "0123456789abcdef");
	if (!str)
		return (0);
	write(1, "0x", 2);
	len = print_string(str);
	free(str);
	return (len + 2);
}

int	print_number(va_list args)
{
	int		num;
	char	*str;
	int		len;

	num = va_arg (args, int);
	str = ft_itoa (num);
	len = print_string (str);
	free (str);
	return (len);
}

int	print_unsigned(va_list args)
{
	unsigned int	num;
	char			*str;
	int				len;

	num = va_arg(args, unsigned int);
	str = ft_utoa(num);
	if (!str)
		return (0);
	len = print_string(str);
	free(str);
	return (len);
}
