/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:20:18 by avieira           #+#    #+#             */
/*   Updated: 2021/04/09 16:36:46 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>


# include <stdio.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

void	error(int *list);
int		ft_isdigit(int c);
int		ft_atoi_of(const char *nptr, int *list);
void	*ft_calloc(size_t count, size_t size);

#endif
