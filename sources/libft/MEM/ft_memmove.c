/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//08 19:50:05 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:18:41 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*t_dst;
	const unsigned char	*t_src;
	int					i;
	int					p_diff;

	if (!dst && !src)
		return (NULL);
	t_dst = dst;
	t_src = src;
	p_diff = 1;
	i = 0;
	if (t_dst > t_src)
	{
		i = len - 1;
		p_diff = -1;
	}
	while ((size_t)i < len && i > -1)
	{
		t_dst[i] = t_src[i];
		i += p_diff;
	}
	return (dst);
}
