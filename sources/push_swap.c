/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:58:03 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 05:45:54 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_ope_strings(char *opes[11])
{
	opes[0] = "sa";
	opes[1] = "sb";
	opes[2] = "ss";
	opes[3] = "pa";
	opes[4] = "pb";
	opes[5] = "ra";
	opes[6] = "rb";
	opes[7] = "rr";
	opes[8] = "rra";
	opes[9] = "rrb";
	opes[10] = "rrr";
}

int	main(int ac, char **av)
{
	t_input		input;
	t_list		*temp;
	char		*opes[11];

	if (ac - 1)
	{
		set_ope_strings(opes);
		alloc_input(&input, ac);
		get_stack(ac, av, &input);
		transform_stack(&input);
		sort_stack(&input);
		temp = input.opes;
		while (temp)
		{
			ft_printf("%s\n", opes[*(int *)temp->content]);
			temp = temp->next;
		}
		free_input(&input);
	}
}
