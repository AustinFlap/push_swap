/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:48:50 by avieira           #+#    #+#             */
/*   Updated: 2021/09/29 13:16:01 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate_a(t_stacks *stacks, t_list *opes, char sorting, t_input *input)
{
	t_opes ope;

	ope = rra;
	reverse_rotate(stacks->a, stacks->len_a);
	if (sorting)
		add_ope(&ope, opes, input);
}
