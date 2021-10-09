/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 01:29:36 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 04:23:03 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			get_min(int *transform, int *list, int len)
{
	int		i;
	int		i_min;

	i = -1;
	i_min = -1;
	while (++i < len)
	{
		if (!transform[i])
		{
			if (i_min == -1)
				i_min = i;
			if (list[i] < list[i_min])
				i_min = i;
		}
	}
	return (i_min);
}

void		transform_order(int *order, int len)
{
	int		*transform_order;
	int		i_min;
	int		i;
	
	if (!(transform_order = ft_calloc(len, sizeof(int))))
		return ;
	i_min = get_min(transform_order, order, len);
	i = 0;
	while (i_min != -1)
	{
		transform_order[i_min] = 1;
		order[i_min] = i++;
		i_min = get_min(transform_order, order, len);
	}
	free(transform_order);
}

void		transform_stack(t_input *input)
{
	int		*list;
	int		len;
	int		i_min;
	int		*transform;
	int		i;

	list = input->stacks.a;
	len = *input->stacks.len_a;
	if (!(transform = ft_calloc(len, sizeof(int))))
		return ;
	i_min = get_min(transform, list, len);
	i = 0;
	while (i_min != -1)
	{
		transform[i_min] = 1;
		list[i_min] = i++;
		i_min = get_min(transform, list, len);
	}
	free(transform);
}
