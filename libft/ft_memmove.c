/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 08:55:50 by mmondell          #+#    #+#             */
/*   Updated: 2021/05/12 14:11:03 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*p_dest;
	unsigned char	*p_src;

	if (dest == src)
		return (dest);
	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	if (dest > src)
	{
		i = n;
		while (i-- > 0)
			p_dest[i] = p_src[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	return (p_dest);
}
