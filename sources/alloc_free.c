/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:23:18 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:01:07 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_input(t_input *input)
{
	if (input->stacks.a)
		free(input->stacks.a);
	if (input->stacks.b)
		free(input->stacks.b);
	if (input->stacks.len_a)
		free(input->stacks.len_a);
	if (input->stacks.len_b)
		free(input->stacks.len_b);
	ft_lstdelall(&input->opes, &free);
}

void	error(t_input *input)
{
	write(1, "Error\n", 6);
	free_input(input);
	exit(EXIT_SUCCESS);
}

void	alloc_input(t_input *input, int ac)
{
	input->opes = NULL;
	input->stacks.b = NULL;
	input->stacks.len_a = NULL;
	input->stacks.len_b = NULL;
	input->stacks.a = ft_calloc(ac - 1, sizeof(int));
	input->stacks.b = ft_calloc(ac - 1, sizeof(int));
	input->stacks.len_a = ft_calloc(1, sizeof(int));
	input->stacks.len_b = ft_calloc(1, sizeof(int));
	if (!input->stacks.a || !input->stacks.b || !input->stacks.len_a
		|| !input->stacks.len_b)
		error(input);
	*input->stacks.len_a = ac - 1;
	*input->stacks.len_b = 0;
}
