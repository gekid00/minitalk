/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_bzero.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gekido <gekido@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/08 14:31:55 by rbourkai		  #+#	#+#			 */
/*   Updated: 2024/11/18 19:10:06 by gekido		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	*ft_bzero(void *pointer, size_t size)
{
	size_t			x;
	unsigned char	*ptr;

	x = 0;
	ptr = (unsigned char *)pointer;
	while (x < size)
	{
		*ptr = 0;
		x++;
		ptr++;
	}
	return (pointer);
}
