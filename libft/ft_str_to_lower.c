/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 21:36:50 by mmondell          #+#    #+#             */
/*   Updated: 2021/07/12 09:19:37 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_to_lower( char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		if (ft_isupper(str[i - 1]))
			str[i - 1] += 32;
	return (str);
}
