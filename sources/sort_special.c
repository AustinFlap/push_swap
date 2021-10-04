/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_special.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:47:55 by avieira           #+#    #+#             */
/*   Updated: 2021/10/04 14:28:59 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		get_find_a(int find[2], t_stacks *stacks)
{
	int		i;
	int		min_delta[2];
	int		delta;

	min_delta[0] = - (*stacks->len_b + *stacks->len_a);
	min_delta[1] = (*stacks->len_b + *stacks->len_a);
	i = -1;
	while (++i < *stacks->len_a)
	{
		delta = stacks->a[i] - *stacks->b;
		if (delta < 0 && delta > min_delta[0])
		{
			find[0] = i + 1;
			min_delta[0] = delta;
		}
		else if (delta > 0 && delta < min_delta[1])
		{
			find[1] = i;
			min_delta[1] = delta;
		}
	}
}

void		rearange_a(t_stacks *stacks, t_input *input)
{
	void	(*rotate)(t_stacks *, char, t_input *);
	int		find[2];
	int		found;

	find[0] = -1;
	find[1] = -1;
	get_find_a(find, stacks);
	found = find[0];
	if (found == -1)
		found = find[1];
	rotate = &rotate_a;
	if (found > (*stacks->len_a) / 2)
	{
		found = *stacks->len_a - found;
		rotate = &reverse_rotate_a;
	}
	while (found-- > 0)
		rotate(stacks, 1, input);
}


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
	while (*stacks->len_b)
	{
		rearange_a(stacks, input);
		push_a(stacks, 1, input);
	}
	while (*stacks->a)
		rotate_a(stacks, 1, input);
}
