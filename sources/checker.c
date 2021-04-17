/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:23:18 by avieira           #+#    #+#             */
/*   Updated: 2021/04/17 21:24:01 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	free_input(t_input *input)
{
	if (input->stacks.a)
		free(input->stacks.a);
	if (input->stacks.b)
		free(input->stacks.b);
	ft_lstdelall(&input->opes, &free);
}

void	error(t_input *input)
{
	ft_printf("Error\n");
	free_input(input);
	exit(EXIT_SUCCESS);
}

void	alloc_input(t_input *input, int ac)
{
	input->opes = NULL;
	input->stacks.b = NULL;
	if (!(input->stacks.a = ft_calloc(ac - 1, sizeof(int))))
		error(input);
	if (!(input->stacks.b = ft_calloc(ac - 1, sizeof(int))))
		error(input);
	input->stacks.len_a = ac - 1;
	input->stacks.len_b = 0;
}

int		main(int ac, char **av)
{
	t_input	input;

	alloc_input(&input, ac);
	get_stack(ac, av, &input);
	get_opes(&input);
	
	t_list *temp = input.opes;
	while (temp)
	{
		ft_printf("--%d\n", *((t_opes *)temp->content));
		temp = temp->next;
	}
	free_input(&input);
}
