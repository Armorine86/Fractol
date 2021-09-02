/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 08:43:33 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/09 08:44:11 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_to_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		if (ft_isupper(str[i - 1]))
			str[i - 1] -= 32;
	return (str);
}
