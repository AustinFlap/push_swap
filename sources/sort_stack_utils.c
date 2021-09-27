/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:17:35 by avieira           #+#    #+#             */
/*   Updated: 2021/09/27 18:59:23 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			find_nearer_of_chunk(t_stacks *stack, int bot, int top, void *rot)
{
	int		i;
	int		min;
	int		max;

	i = 0;
	min = -1;
	max = -1;
	while (i < *stack->len_a && min == -1)
	{
		if (stack->a[i] >= bot && stack->a[i] <= top)
			min = i;
		i++;
	}
	i = *stack->len_a - 1;
	while (i > -1 && max == -1)
	{
		if (stack->a[i] >= bot && stack->a[i] <= top)
			max = i;
		i--;
	}
	rot = &rotate;
	if (min <= (*stack->len_a - max))
		return (min);
	rot = &reverse_rotate;
	return (max);
}
