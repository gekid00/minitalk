/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlcpy.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gekido <gekido@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/16 11:40:29 by rbourkai		  #+#	#+#			 */
/*   Updated: 2024/11/18 19:10:06 by gekido		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size > 0)
	{
		while (src[count] && count < size - 1)
		{
			dest[count] = src[count];
			count++;
		}
		dest[count] = '\0';
	}
	return (ft_strlen(src));
}
