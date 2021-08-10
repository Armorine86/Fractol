/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armorine <armorine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 09:05:50 by mmondell          #+#    #+#             */
/*   Updated: 2021/05/18 10:15:47 by armorine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1)
	{
		dest[i] = source[i];
		if (source[i] == '\0')
			break ;
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
