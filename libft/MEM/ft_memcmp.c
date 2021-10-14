/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//08 20:19:10 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:15:25 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*c1;
	const unsigned char	*c2;

	c1 = s1;
	c2 = s2;
	if (!*c1 && !*c2)
		return (0);
	else
		while (n--)
			if (*c1++ != *c2++)
				return (*--c1 - *--c2);
	return (0);
}
