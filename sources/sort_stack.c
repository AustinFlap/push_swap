/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:34:42 by avieira           #+#    #+#             */
/*   Updated: 2021/09/30 15:21:57 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		rearange_b(t_stacks *stacks, t_input *input)
{
	int		i;
	int		find;
	int		min_delta;
	int		delta;
	void	(*rotate)(t_stacks *, char, t_input *);

	i = -1;
	min_delta = - (*stacks->len_b + *stacks->len_a);
	while (++i < *stacks->len_b)
	{
		delta = stacks->b[i] - *stacks->a;
		if (delta < 0 && delta > min_delta)
		{
			find = i;
			min_delta = delta;
		}
	}
	rotate = &rotate_b;
	if (find > (*stacks->len_b - 1) / 2)
	{
		find = *stacks->len_b - find;
		rotate = &reverse_rotate_b;
	}
	while (find--)
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
	//printf("\nSORT_CHUNK\n");
	//printf("bot : %d     top : %d\n", bot, top);
	//printf("stack[%d] = %d   stack[%d] = %d\n\n", chunk.min, input->stacks.a[chunk.min], chunk.max,input->stacks.a[chunk.max]);
	while (*input->stacks.a != chunk.max_value && *input->stacks.a != chunk.min_value)
		chunk.rotate(&input->stacks, 1, input);
	i = -1;
	while (++i < chunk.size)
	{
		if (*input->stacks.a >= bot && *input->stacks.a <= top && *input->stacks.len_a)
		{
			if (*input->stacks.len_b > 1)
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
	//printf("n_chunk = %d\n", n_chunk);
	while (*input->stacks.len_b)
		push_a(&input->stacks, 1, input);
}
