/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:20:18 by avieira           #+#    #+#             */
/*   Updated: 2021/04/14 14:03:48 by avieira          ###   ########.fr       */
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

typedef struct	s_opes_list
{
	t_opes		ope;
	void		*next;
}				t_opes_list;

typedef struct	s_stacks
{
	int *a;
	int *b;
	int len_a;
	int len_b;
}				t_stacks;

void	error(int *list);
int		ft_atoi_of(const char *nptr, int *list);
int		ft_isdigit(int c);
void	*ft_calloc(size_t count, size_t size);


#endif
