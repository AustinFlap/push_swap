/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 21:24:26 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:37:26 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdelall(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (del)
	{
		while (*lst)
		{
			temp = *lst;
			del(temp->content);
			*lst = (*lst)->next;
			free(temp);
		}
	}
}
