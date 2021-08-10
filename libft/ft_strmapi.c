/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:52:33 by mmondell          #+#    #+#             */
/*   Updated: 2021/05/10 11:20:43 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	new = ft_strdup(s);
	i = 0;
	if (!s || !f || !new)
		return (0);
	while (new[i])
	{
		new[i] = f(i, new[i]);
		i++;
	}
	return (new);
}
