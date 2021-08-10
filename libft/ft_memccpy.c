/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armorine <armorine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 08:31:44 by mmondell          #+#    #+#             */
/*   Updated: 2021/05/21 10:39:00 by armorine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dest, const void *restrict src,
			int c, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (0);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *) src)[i];
		if ((unsigned char)c == ((unsigned char *)src)[i])
			return (dest + i + 1);
		i++;
	}
	return (0);
}
