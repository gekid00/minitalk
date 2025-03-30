/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekido <gekido@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:13:45 by gekido            #+#    #+#             */
/*   Updated: 2025/02/08 08:56:43 by gekido           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		print_hex(va_list args, char format);
int		print_percent(void);
int		print_char(va_list args);
int		print_string(char *c);
int		print_pointer(va_list args);
int		print_number(va_list args);
int		print_unsigned(va_list args);
char	*ft_utoa_base(unsigned long n, const char *base);
char	*ft_itoa(int nb);
char	*ft_utoa(unsigned int n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
int		ft_atoi(const char *str);

#endif