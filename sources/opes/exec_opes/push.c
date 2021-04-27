/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:30:42 by avieira           #+#    #+#             */
/*   Updated: 2021/04/27 12:52:50 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	push(int *a, int *b, int *len_a, int *len_b)
{
	if (!*len_b)
		return ;
	a[*len_a] = b[0];
	rotate(b, len_b);
	(*len_b)--;
	reverse_rotate(a, len_a);
	(*len_a)++;
}
