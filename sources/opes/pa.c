/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:58:43 by avieira           #+#    #+#             */
/*   Updated: 2021/09/29 13:47:05 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_a(t_stacks *stacks, t_list *opes, char sorting, t_input *input)
{
	t_opes	ope;

	ope = pa;
	push(stacks->a, stacks->b, stacks->len_a, stacks->len_b);
	if (sorting)
		add_ope(&ope, opes, input);
}
