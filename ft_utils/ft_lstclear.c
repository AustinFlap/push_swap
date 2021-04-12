/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:42:27 by avieira           #+#    #+#             */
/*   Updated: 2019/10/14 17:07:57 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = (*lst);
	(*del)((*lst)->content);
	*lst = (*lst)->next;
	temp = NULL;
	while (*lst)
	{
		temp = (*lst);
		(*del)((*lst)->content);
		*lst = (*lst)->next;
		free(temp);
	}
}
