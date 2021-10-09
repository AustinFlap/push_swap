/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//10 15:23:52 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:16:41 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char				*alloc;
	size_t				i;

	alloc = malloc(size * count);
	if (!alloc)
		return (NULL);
	i = 0;
	while (i < count * size)
		alloc[i++] = 0;
	return (alloc);
}
