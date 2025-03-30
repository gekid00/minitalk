/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:44:31 by gekido            #+#    #+#             */
/*   Updated: 2024/12/23 16:55:40 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_hex(va_list args, char format)
{
	unsigned int	num;
	char			*str;
	int				len;

	num = va_arg(args, unsigned int);
	if (format == 'x')
		str = ft_utoa_base(num, "0123456789abcdef");
	else
		str = ft_utoa_base(num, "0123456789ABCDEF");
	if (!str)
		return (free(str), 0);
	len = print_string(str);
	free(str);
	return (len);
}

int	print_percent(void)
{
	write (1, "%", 1);
	return (1);
}
