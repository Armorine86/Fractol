/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 08:45:06 by biohazard         #+#    #+#             */
/*   Updated: 2021/08/09 08:42:53 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long long num, int base_len)
{
	unsigned int	i;

	i = 1;
	if (num < 0)
		num = -num;
	while (num > base_len)
	{
		num /= base_len;
		i++;
	}
	return (i);
}
