/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//08 19:06:03 by avieira           #+#    #+#             */
/*   Updated: 20..//17 18:32:40 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*t_dst;
	const unsigned char	*t_src;
	size_t				i;

	i = 0;
	t_dst = dst;
	t_src = src;
	while (i < n)
	{
		t_dst[i] = t_src[i];
		i++;
		if (t_src[i] == (unsigned char)c && i < n)
		{
			t_dst[i] = t_src[i];
			return (t_dst + i + 1);
		}
	}
	return (NULL);
}
