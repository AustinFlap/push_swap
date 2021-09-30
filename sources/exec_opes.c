/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_opes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 00:22:55 by avieira           #+#    #+#             */
/*   Updated: 2021/09/30 04:08:50 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_stacks(int *a, int *b, int *len_a, int *len_b)
{
	int	i;

	i = 0;
	ft_printf("\n");
	while (i < *len_a || i < *len_b)
	{
		if (i < *len_a)
			ft_printf("%d ", a[i]);
		else
			ft_printf("  ");
		if (i < *len_b)
			ft_printf("%d \n", b[i]);
		else
			ft_printf("  \n");
		i++;
	}
	ft_printf("- -\na b\n---\n");
}

void	exec_opes(t_input *input)
{
	void	(*f[11])(t_stacks *, char, t_input *);
	t_list	*temp;
	t_stacks *stack;

	f[0] = &swap_a;
	f[1] = &swap_b;
	f[2] = &swap_double;
	f[3] = &push_a;
	f[4] = &push_b;
	f[5] = &rotate_a;
	f[6] = &rotate_b;
	f[7] = &rotate_double;
	f[8] = &reverse_rotate_a;
	f[9] = &reverse_rotate_b;
	f[10] = &reverse_rotate_double;
	temp = input->opes;
	stack = &input->stacks;
	while (temp)
	{
		f[*((int *)temp->content)](stack, 0, input);
		display_stacks(stack->a, stack->b, stack->len_a, stack->len_b);
		temp = temp->next;
	}
}
