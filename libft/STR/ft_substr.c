/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//07 14:17:04 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:43:12 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				i;
	char			*substr;
	unsigned int	len_s;

	len_s = 0;
	if (!s)
		return (NULL);
	while (s[len_s])
		len_s++;
	if (len > len_s - start)
		len = len_s - start;
	if (start > len_s)
		len = 0;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (len-- && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}
