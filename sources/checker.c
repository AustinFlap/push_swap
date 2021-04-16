/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:23:18 by avieira           #+#    #+#             */
/*   Updated: 2021/04/16 22:38:20 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(void)
{
	ft_printf("Error\n");
	exit(0);
}

void	alloc_input(t_input *input, int ac)
{
	*(input->opes) = NULL;
	if (!(input->stacks.a = ft_calloc(ac - 1, sizeof(int))))
		error();
	if (!(input->stacks.b = ft_calloc(ac - 1, sizeof(int))))
	{
		free(input->stacks.a);
		error();
	}
	input->stacks.len_a = ac - 1;
	input->stacks.len_b = 0;
}

int		main(int ac, char **av)
{
	t_input	input;

	alloc_input(&input, ac);
	get_stack(ac, av, input.stacks.a);
	get_opes(input.opes);
	
	t_list *temp = *(input.opes);
	while (temp)
	{
		ft_printf("--%d\n", *((t_opes *)temp->content));
		temp = temp->next;
	}
}
