/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:58:43 by avieira           #+#    #+#             */
/*   Updated: 2021/09/29 13:15:22 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_b(t_stacks *stacks, t_list *opes, char sorting, t_input *input)
{
	t_opes	ope;

	ope = pb;
	push(stacks->b, stacks->a, stacks->len_b, stacks->len_a);
	if (sorting)
		add_ope(&ope, opes, input);
}
