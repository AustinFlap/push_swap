/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//13 12:45:16 by avieira           #+#    #+#             */
/*   Updated: 20..//13 14:40:36 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list		*new;

	if (!(new = malloc(sizeof(new))))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
