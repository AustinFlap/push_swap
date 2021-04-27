/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_opes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 00:22:55 by avieira           #+#    #+#             */
/*   Updated: 2021/04/27 01:44:30 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exec_opes(t_input *input)
{
	void	(*f[11])(int *, int *, int *, int *);
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
		f[*((int *)temp->content)](stack->a, stack->b, stack->len_a, stack->len_b);
		temp = temp->next;
	}
}
