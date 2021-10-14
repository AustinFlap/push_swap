/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20..//07 14:49:28 by avieira           #+#    #+#             */
/*   Updated: 2021/10/09 13:53:28 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	len_to_sep(char const *s, char c, int i)
{
	int	l;

	l = 0;
	while (s[i] != c && s[i])
	{
		l++;
		i++;
	}
	return (l);
}

static int	word_create(char const *s, char c, int i, char *split)
{
	int	a;

	a = 0;
	while (s[i] != c && s[i])
	{
		split[a] = s[i];
		a++;
		i++;
	}
	split[a] = 0;
	return (i);
}

static void	*free_array(char **split, int j)
{
	int	i;

	i = 0;
	while (i <= j)
		free(split[i++]);
	free(split);
	return (NULL);
}

void	*loop(char **split, int n_words, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++j < n_words)
	{
		while (s[i] == c && s[i])
			i++;
		split[j] = malloc(sizeof(char) * (len_to_sep(s, c, i) + 1));
		if (!split[j])
			return (free_array(split, j));
		i = word_create(s, c, i, split[j]);
		while (s[i] == c && s[i])
			i++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		n_words;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	n_words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			n_words++;
			while (s[i] != c && s[i])
				i++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	split = malloc(sizeof(char *) * (n_words + 1));
	if (!split)
		return (NULL);
	if (!loop(split, n_words, s, c))
		return (NULL);
	return (split);
}
