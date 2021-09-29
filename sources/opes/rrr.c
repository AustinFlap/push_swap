/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:48:50 by avieira           #+#    #+#             */
/*   Updated: 2021/09/29 13:16:18 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate_double(t_stacks *stacks, t_list *opes, char sorting, t_input *input)
{
	t_opes ope;

	ope = rrr;
	reverse_rotate(stacks->a, stacks->len_a);
	reverse_rotate(stacks->b, stacks->len_b);
	if (sorting)
		add_ope(&ope, opes, input);
}
