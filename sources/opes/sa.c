/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:58:43 by avieira           #+#    #+#             */
/*   Updated: 2021/09/29 13:16:25 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap_a(t_stacks *stacks, t_list *opes, char sorting, t_input *input)
{
	t_opes ope;

	ope = sa;
	swap(stacks->a, stacks->len_a);
	if (sorting)
		add_ope(&ope, opes, input);
}
