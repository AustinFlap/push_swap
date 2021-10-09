/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_ope_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:23:44 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 15:47:43 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	del_ope_one(t_list **opes, t_list *to_del)
{
	t_list	*temp;

	temp = *opes;
	if (to_del == *opes)
		*opes = (*opes)->next;
	else
	{
		while (temp->next != to_del)
			temp = temp->next;
		temp->next = to_del->next;
	}
	ft_lstdelone(to_del, &free);
}
