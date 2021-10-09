/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:58:03 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 04:21:33 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				main(int ac, char **av)
{
	t_input		input;
	t_list		*temp;

	if (ac - 1)
	{
		alloc_input(&input, ac);
		get_stack(ac, av, &input);
		transform_stack(&input);
		sort_stack(&input);

		char *opes[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};

		temp = input.opes;
		while (temp)
		{
			printf("%s\n", opes[*(int *)temp->content]);
			temp = temp->next;
		}
		free_input(&input);
	}
}
