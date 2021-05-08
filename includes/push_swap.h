/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:20:18 by avieira           #+#    #+#             */
/*   Updated: 2021/05/09 00:28:58 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../sources/libft/includes/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef enum	e_opes
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}				t_opes;

typedef struct	s_stacks
{
	int			*a;
	int			*b;
	int			*len_a;
	int			*len_b;
}				t_stacks;

typedef struct	s_input
{
	t_stacks	stacks;
	t_list		*opes;
}				t_input;

void			error(t_input *input);
void			alloc_input(t_input *input, int ac);
void			free_input(t_input *input);
int				ft_atoi_of(const char *nptr, t_input *input);
void			get_stack(int ac, char **av, t_input *input);
void			get_opes(t_input *input);
void			exec_opes(t_input *input);
void			check_stacks(int *a, int *len_a, int *len_b);
void			swap_a(int *a, int *b, int *len_a, int *len_b);
void			swap_b(int *a, int *b, int *len_a, int *len_b);
void			swap_double(int *a, int *b, int *len_a, int *len_b);
void			push_a(int *a, int *b, int *len_a, int *len_b);
void			push_b(int *a, int *b, int *len_a, int *len_b);
void			rotate_a(int *a, int *b, int *len_a, int *len_b);
void			rotate_b(int *a, int *b, int *len_a, int *len_b);
void			rotate_double(int *a, int *b, int *len_a, int *len_b);
void			reverse_rotate_a(int *a, int *b, int *len_a, int *len_b);
void			reverse_rotate_b(int *a, int *b, int *len_a, int *len_b);
void			reverse_rotate_double(int *a, int *b, int *len_a, int *len_b);
void			swap(int *a, int *len_a);
void			push(int *a, int *b, int *len_a, int *len_b);
void			rotate(int *a, int *len_a);
void			reverse_rotate(int *a, int *len_a);
void			reverse_array_index(int *a, int start, int end);

#endif
