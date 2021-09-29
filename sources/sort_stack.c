/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:34:42 by avieira           #+#    #+#             */
/*   Updated: 2021/09/29 13:22:52 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sort_chunk(t_input *input, int bot, int top)
{
	t_chunk	chunk;
	int		i;

	chunk.rotate = NULL;
	find_nearer_of_chunk(&input->stacks, bot, top, &chunk);
	chunk.size = 1 + chunk.max - chunk.min;
	chunk.min_value = input->stacks.a[chunk.min];
	chunk.max_value = input->stacks.a[chunk.max];
	printf("bot : %d     top : %d\n", bot, top);
	printf("stack[%d] = %d   stack[%d] = %d\n\n", chunk.min, input->stacks.a[chunk.min], chunk.max,input->stacks.a[chunk.max]);
	i = 0;
	while (*input->stacks.a != chunk.max_value && *input->stacks.a != chunk.min_value)
	{
		chunk.rotate(&input->stacks, input->opes, 1, input);
		display_stacks(input->stacks.a, input->stacks.b, input->stacks.len_a, input->stacks.len_b);
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
	{
		if (*input->stacks.len_a < ((i + 1) * SIZE_CHUNK - 1))
			sort_chunk(input, i * SIZE_CHUNK, *input->stacks.len_a - 1);
		else
			sort_chunk(input, i * SIZE_CHUNK, ((i + 1) * SIZE_CHUNK - 1));
	}
	printf("n_chunk = %d\n", n_chunk);
}
