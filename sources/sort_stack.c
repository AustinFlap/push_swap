/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:34:42 by avieira           #+#    #+#             */
/*   Updated: 2021/09/27 19:00:00 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sort_chunk(t_input *input, int bot, int top)
{
	int		nearer;
	void	(*rotate)(int *, int *, int *, int*);

	rotate = NULL;
	nearer = find_nearer_of_chunk(&input->stacks, bot, top, rotate);
	printf("bot : %d     top : %d\n", bot, top);
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
