/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:58:03 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 16:39:20 by avieira          ###   ########.fr       */
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

void	join_opes(t_list *opes, int ope_a, int ope_b, int ope_join)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = opes;
	while (tmp1)
	{
		if (*(int *)tmp1->content == ope_a || *(int *)tmp1->content == ope_b)
		{
			tmp2 = tmp1;
			while ((*(int *)tmp1->content == *(int *)tmp2->content
					|| *(int *)tmp1->content == rr) && tmp1->next)
				tmp1 = tmp1->next;
			if ((*(int *)tmp1->content == ope_a || *(int *)tmp1->content
					== ope_b) && *(int *)tmp1->content != *(int *)tmp2->content)
			{
				*(int *)tmp1->content = ope_join;
				tmp1 = tmp2->next;
				del_ope_one(&opes, tmp2);
			}
			else
				tmp1 = tmp1->next;
		}
		else
			tmp1 = tmp1->next;
	}
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
		join_opes(input.opes, ra, rb, rr);
		join_opes(input.opes, rra, rrb, rrr);
		temp = input.opes;
		while (temp)
		{
			ft_printf("%s\n", opes[*(int *)temp->content]);
			temp = temp->next;
		}
		free_input(&input);
	}
}
