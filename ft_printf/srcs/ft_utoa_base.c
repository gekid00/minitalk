/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 03:07:09 by gekido            #+#    #+#             */
/*   Updated: 2024/12/23 16:55:57 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	get_num_len_base(unsigned long n, int base_len)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_utoa_base(unsigned long n, const char *base)
{
	char	*str;
	int		len;
	int		base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (NULL);
	len = get_num_len_base(n, base_len);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}
