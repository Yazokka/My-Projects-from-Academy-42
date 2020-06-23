/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gciub <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:18:37 by gciub             #+#    #+#             */
/*   Updated: 2016/11/25 20:36:54 by gciub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **link, void (*del)(void *, size_t))
{
	t_list	*next;

	while (*link != NULL)
	{
		next = (*link)->next;
		ft_lstdelone(link, del);
		*link = next;
	}
}
