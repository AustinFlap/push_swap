/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:15:30 by avieira           #+#    #+#             */
/*   Updated: 2019/10/17 20:04:30 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_strl(const char *s)
{
	int l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(s = malloc(sizeof(char) * (ft_strl(s1) + ft_strl(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s[j++] = s2[i++];
	s[j] = 0;
	return (s);
}
