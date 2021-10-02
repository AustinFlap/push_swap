/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:34:42 by avieira           #+#    #+#             */
/*   Updated: 2021/10/02 21:11:15 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			get_find(t_stacks *stacks)
{
	int		i;
	int		min_delta[2];
	int		delta;
	int		find;

	min_delta[0] = - (*stacks->len_b + *stacks->len_a);
	min_delta[1] = (*stacks->len_b + *stacks->len_a);
	i = -1;
	find = -1;
	while (++i < *stacks->len_b)
	{
		delta = stacks->b[i] - *stacks->a;
		if (delta < 0 && delta > min_delta[0])
		{
			find = i;
			min_delta[0] = delta;
		}
	}
	i = -1;
	if (find == -1)
	{
		while (++i < *stacks->len_b)
		{
			delta = stacks->b[i] - *stacks->a;
			if (delta > 0 && delta < min_delta[1])
			{
				find = i + 1;
				min_delta[1] = delta;
			}
		}
	}
	return (find);
}

void		rearange_b(t_stacks *stacks, t_input *input)
{
	void	(*rotate)(t_stacks *, char, t_input *);
	int		found;

	found = get_find(stacks);
	rotate = &rotate_b;
	if (found > (*stacks->len_b) / 2)
	{
		found = *stacks->len_b - found;
		rotate = &reverse_rotate_b;
	}
	while (found-- > 0)
		rotate(stacks, 1, input);
}

void		sort_chunk(t_input *input, int bot, int top)
{
	t_chunk	chunk;
	int		i;

	chunk.rotate = NULL;
	find_nearer_of_chunk(&input->stacks, bot, top, &chunk);
	chunk.size = 1 + chunk.max - chunk.min;
	chunk.min_value = input->stacks.a[chunk.min];
	chunk.max_value = input->stacks.a[chunk.max];
	while (*input->stacks.a != chunk.max_value && *input->stacks.a != chunk.min_value)
		chunk.rotate(&input->stacks, 1, input);
	i = -1;
	while (++i < chunk.size)
	{
		if (*input->stacks.a >= bot && *input->stacks.a <= top && *input->stacks.len_a)
		{
			if (*input->stacks.len_b)
				rearange_b(&input->stacks, input);
			push_b(&input->stacks, 1, input);
			i--;
		}
		else
			chunk.rotate(&input->stacks, 1, input);
	}
}

void		sort_stack(t_input* input)
{
	int		n_chunk;
	int		i;

	n_chunk = *input->stacks.len_a / SIZE_CHUNK;
	if (*input->stacks.len_a % SIZE_CHUNK)
		n_chunk++;
	i = -1;
	while (++i < n_chunk)
		sort_chunk(input, i * SIZE_CHUNK, ((i + 1) * SIZE_CHUNK - 1));
	while (*input->stacks.b != *input->stacks.len_b - 1)
		rotate_b(&input->stacks, 1, input);
	while (*input->stacks.len_b)
		push_a(&input->stacks, 1, input);
}
