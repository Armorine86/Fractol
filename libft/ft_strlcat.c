/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 09:59:55 by mmondell          #+#    #+#             */
/*   Updated: 2021/05/28 15:45:41 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;
	size_t	j;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	j = d_len;
	if (d_len > size)
		return (size + s_len);
	if (size == 0)
		return (s_len);
	while (src[i])
	{
		if (j >= size - 1)
			break ;
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (d_len + s_len);
}
