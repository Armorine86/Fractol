/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:40:15 by mmondell          #+#    #+#             */
/*   Updated: 2021/05/10 09:00:58 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnum(char *str, int temp, int n)
{
	char	tmp;
	int		buff;

	while (temp)
	{
		buff = temp % 10;
		temp = temp / 10;
		tmp = buff + '0';
		str[n - 1] = tmp;
		n--;
	}
}

int	ft_totaldigit(int n)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_print_min(char *str)
{
	ft_memcpy(str, "-2147483648", 11);
	str[11] = '\0';
	return (str);
}

int	ft_minimum_int(int n)
{
	if (n == -2147483648)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		temp;	

	i = 0;
	if (n > 0)
		str = ft_calloc((ft_totaldigit(n) + 1), sizeof(char));
	else
		str = ft_calloc((ft_totaldigit(n) + 2), sizeof(char));
	if (str == 0)
		return (0);
	if (ft_minimum_int(n))
		return (ft_print_min(str));
	*str = '0';
	while (n < 0)
	{
		n *= -1;
		*str = '-';
		i++;
	}
	temp = n;
	i += ft_totaldigit(n);
	ft_putnum(str, temp, i);
	return (str);
}
