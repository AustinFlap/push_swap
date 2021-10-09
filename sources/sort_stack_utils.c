/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:17:35 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 03:52:54 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		add_ope(t_opes *ope, t_input *input)
{
	t_list	*new_ope;

	if (!(new_ope = ft_lstnew(ope)))
		error(input);
	ft_lstadd_back(&input->opes, new_ope);
	//display_stacks(input->stacks.a, input->stacks.b, input->stacks.len_a, input->stacks.len_b);
}

int			is_sort(int *stack, int len)
{
	int		temp;
	int		i;

	i = 0;
	temp = stack[i];
	while (++i < len)
	{
		if (stack[i] < temp)
			return (0);
		temp = stack[i];
	}
	return (1);
}

void		find_nearer_of_chunk(t_stacks *stack, int bot, int top, t_chunk *chunk)
{
	int		i;

	i = 0;
	chunk->min = -1;
	chunk->max = -1;
	while (i < *stack->len_a && chunk->min == -1)
	{
		if (stack->a[i] >= bot && stack->a[i] <= top)
			chunk->min = i;
		i++;
	}
	i = *stack->len_a - 1;
	while (i > -1 && chunk->max == -1)
	{
		if (stack->a[i] >= bot && stack->a[i] <= top)
			chunk->max = i;
		i--;
	}
	if (chunk->min < (*stack->len_a - chunk->max))
		chunk->rotate = &rotate_a;
	else
		chunk->rotate = &reverse_rotate_a;
}

void	shift_b_before_push(t_stacks *stacks, t_input *input)
{
	int i;
	void	(*rotate)(t_stacks *, char, t_input *);;

	i = 0;
	while (stacks->b[i])
		i++;
	rotate = &rotate_b;
	if (i > (*stacks->len_b) / 2)
	{
		i = *stacks->len_b - i - 1;
		rotate = &reverse_rotate_b;
	}
	else
		i++;
	while (i--)
		rotate(stacks, 1, input);
}

void		define_chunk_order(int n_chunk, t_stacks *stacks, t_input *input, int *order)
{
	t_chunk *chunk_order;
	int			i;

	if (!(chunk_order = malloc(sizeof(t_chunk) * n_chunk)))
	//if (!(chunk_order = ft_calloc(n_chunk, sizeof(int))))
		error(input);
	i = -1;
	while (++i < n_chunk)
	{
		find_nearer_of_chunk(stacks, i * SIZE_CHUNK, ((i + 1) * SIZE_CHUNK - 1),
															&chunk_order[i]);
		order[i] = chunk_order[i].max - chunk_order[i].min;
	}
	transform_order(order, n_chunk);
	free(chunk_order);
}
