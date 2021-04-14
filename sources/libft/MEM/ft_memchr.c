/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//08 20:14:59 by avieira           #+#    #+#             */
/*   Updated: 20..//14 17:08:45 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		d;
	const unsigned char	*temp;

	temp = s;
	d = c;
	while (n--)
		if (*temp++ == d)
			return ((void *)--temp);
	return (NULL);
}
