/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:29:03 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/07 20:17:45 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long num)
{
	if (num < 0)
		ft_putnbr(num * -1);
	else if (num >= 0 && num <= 9)
		ft_putchar('0' + num);
	else
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
}
