/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 09:12:43 by mmondell          #+#    #+#             */
/*   Updated: 2021/05/10 09:07:30 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tail;

	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tail = ft_lstlast(*alst);
	tail->next = new;
}
