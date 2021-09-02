/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:44:59 by armorine          #+#    #+#             */
/*   Updated: 2021/08/09 08:42:22 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	solve_base(unsigned long long nbr, char *base, int len)
{
	unsigned int	num;
	char			c;

	num = nbr;
	if (num >= (unsigned int)len)
		solve_base(num / len, base, len);
	c = base[num % len];
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1])
			return (0);
		i++;
	}
	if (i <= 0)
		return (0);
	return (1);
}

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	len;

	len = 0;
	if (check_base(base) == 1)
	{
		while (base[len])
			len++;
		solve_base(nbr, base, len);
	}
}*/

void	ft_putnbr_base(long long num, int base_len, char *base)
{
	char	*decimal;
	char	*hex;
	char	*binary;
	char	c;

	decimal = "0123456789";
	hex = "0123456789abcdef";
	binary = "01";
	if (!ft_strcmp(base, decimal) || !ft_strcmp(base, hex)
		|| !ft_strcmp(base, binary))
	{
		if (num >= base_len)
			ft_putnbr_base(num / base_len, base_len, base);
		c = base[(num % base_len)];
		write(1, &c, 1);
	}
}
