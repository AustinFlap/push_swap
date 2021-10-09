/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//13 14:25:33 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:39:11 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	*lstclear(t_list **lst, void (*del)(void *))
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
	return (NULL);
}

void	*alloc_new_lst(t_list *lst, t_list **new_lst)
{
	*new_lst = NULL;
	if (lst)
	{
		*new_lst = malloc(sizeof(t_list *));
		if (!*new_lst)
			return (NULL);
	}
	return (*new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*a;
	t_list	*b;

	alloc_new_lst(lst, &new_lst);
	if (!new_lst)
		return (NULL);
	a = new_lst;
	b = new_lst;
	while (lst)
	{
		a = b;
		a->content = (*f)(lst->content);
		if (lst->next)
		{
			b = malloc(sizeof(b));
			if (!b)
				return (lstclear(&new_lst, del));
			a->next = b;
		}
		else
			a->next = NULL;
		lst = lst->next;
	}
	return (new_lst);
}
