/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:06:03 by avieira           #+#    #+#             */
/*   Updated: 2019/10/17 18:37:30 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*t_dst;
	const unsigned char	*t_src;

	t_dst = dst;
	t_src = src;
	if (!dst && !src)
		return (NULL);
	while (n--)
		*t_dst++ = *t_src++;
	return (dst);
}
