/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:20:18 by avieira           #+#    #+#             */
/*   Updated: 2021/04/16 22:08:05 by avieira          ###   ########.fr       */
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
	int			len_a;
	int			len_b;
}				t_stacks;

typedef struct	s_input
{
	t_stacks	stacks;
	t_list		**opes;
}				t_input;

void			error(void);
int				ft_atoi_of(const char *nptr);
void			get_stack(int ac, char **av, int *a);
void			get_opes(t_list **opes);

#endif
