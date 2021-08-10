/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armorine <armorine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 08:42:57 by mmondell          #+#    #+#             */
/*   Updated: 2021/05/21 10:40:17 by armorine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*len;

	len = s;
	while (*len)
		len++;
	while (len != s && *len != c)
		len--;
	if (*len == c)
		return ((char *)len);
	return (0);
}
