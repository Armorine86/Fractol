/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 09:40:04 by mmondell          #+#    #+#             */
/*   Updated: 2021/09/01 12:13:08 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_line(int fd, int *ret, int i)
{
	char	c;
	char	*str;

	if (!read(fd, &c, 1))
		c = 0;
	if (c == '\n' || c == 0)
	{
		str = malloc(sizeof(char) * (i + 1));
		str[i] = 0;
		*ret = 1;
		if (c == 0)
			*ret = 0;
		return (str);
	}
	else
	{
		str = read_line(fd, ret, i + 1);
		str[i] = c;
	}
	return (str);
}

int	get_next_line(int fd, char **line)
{
	int	ret;

	ret = 1;
	*line = read_line(fd, &ret, 0);
	return (ret);
}
