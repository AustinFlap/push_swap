/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_special.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:47:55 by avieira           #+#    #+#             */
/*   Updated: 2021/10/04 13:35:57 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sort_little(t_input *input, t_stacks *stacks)
{
	int		diff[3];
	int		c;
	int		i;

	if (*stacks->len_a == 2)
	{
		swap_a(stacks, 1, input);
		return ;
	}
	while (*stacks->len_a > 3)
		push_b(stacks, 1, input);
	i = -1;
	c = 0;
	diff[0] = stacks->a[1] - stacks->a[0];
	diff[1] = stacks->a[2] - stacks->a[1];
	diff[2] = stacks->a[0] - stacks->a[2];
	while (++i < 3)
		if (diff[i] < 0)
			c++;
	if (c > 1)
		swap_a(stacks, 1, input);
	if (stacks->a[1] < stacks->a[0] && stacks->a[1] < stacks->a[2])
		rotate_a(stacks, 1, input);
	if (stacks->a[2] < stacks->a[0] && stacks->a[2] < stacks->a[1])
		reverse_rotate_a(stacks, 1, input);
}
