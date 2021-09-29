/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:17:35 by avieira           #+#    #+#             */
/*   Updated: 2021/09/29 12:29:33 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		find_nearer_of_chunk(t_stacks *stack, int bot, int top, t_chunk *chunk)
{
	int		i;

	i = 0;
	chunk->min = -1;
	chunk->max = -1;
	while (i < *stack->len_a && chunk->min == -1)
	{
		if (stack->a[i] >= bot && stack->a[i] <= top)
			chunk->min = i;
		i++;
	}
	i = *stack->len_a - 1;
	while (i > -1 && chunk->max == -1)
	{
		if (stack->a[i] >= bot && stack->a[i] <= top)
			chunk->max = i;
		i--;
	}
	if (chunk->min <= (*stack->len_a - chunk->max))
		chunk->rotate = &rotate;
	else
		chunk->rotate = &reverse_rotate;
}
