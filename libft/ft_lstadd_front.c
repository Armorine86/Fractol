/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armorine <armorine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 08:34:01 by mmondell          #+#    #+#             */
/*   Updated: 2021/05/21 10:38:22 by armorine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	if (!alst)
	{
		*alst = new;
		return ;
	}
	new->next = *alst;
	*alst = new;
}
