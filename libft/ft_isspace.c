/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 10:36:17 by mmondell          #+#    #+#             */
/*   Updated: 2021/08/09 10:42:44 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define UCHAR unsigned char

int	ft_isspace(int c)
{
	return (((UCHAR)c >= '\t' && (UCHAR)c <= '\r') || (UCHAR)c == ' ');
}
