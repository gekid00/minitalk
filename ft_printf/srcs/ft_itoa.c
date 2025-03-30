/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:13:02 by rbourkai          #+#    #+#             */
/*   Updated: 2024/12/23 16:55:48 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	check_len(size_t nb)
{
	size_t	temp;
	size_t	len;

	len = 0;
	temp = nb;
	if (nb == 0)
		return (1);
	if (nb == (long unsigned int)-2147483648)
	{
		nb = 2147483647;
		len = 10;
	}
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	return (len);
}

static char	*itoa_exec(size_t len, int additionnal_char, size_t nb,
			char *result)
{
	size_t	i;

	i = 0;
	while (nb > 0)
	{
		result[len - i - 1 + additionnal_char] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	if (additionnal_char == 1)
		result[0] = '-';
	return (result);
}

static char	*ft_intmin(char	*result)
{
	ft_strlcpy(result, "-2147483648", 12);
	return (result);
}

static char	*case_zero(char *result)
{
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*ft_itoa(int nb)
{
	size_t	len;
	int		additionnal_char;
	char	*result;

	additionnal_char = 0;
	if (nb == -2147483648)
	{
		result = malloc(12 * sizeof(char));
		if (!result)
			return (NULL);
		return (ft_intmin(result));
	}
	if (nb < 0)
	{
		nb = -nb;
		additionnal_char = 1;
	}
	len = check_len(nb);
	result = malloc((len + 1 + additionnal_char) * sizeof(char));
	if (!result)
		return (NULL);
	if (nb == 0)
		return (case_zero(result));
	result[len + additionnal_char] = '\0';
	return (itoa_exec (len, additionnal_char, nb, result));
}
