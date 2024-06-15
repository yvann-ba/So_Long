/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 08:18:45 by yvann             #+#    #+#             */
/*   Updated: 2024/01/16 14:29:35 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wcount(const char *str, char sep)
{
	size_t	i;
	size_t	cnt;

	cnt = 0;
	i = 1;
	if (!*str)
		return (0);
	if (str [i - 1] != sep)
		cnt++;
	while (str[i])
	{
		if (str[i] != sep && str[i - 1] == sep)
			cnt++;
		i++;
	}
	return (cnt);
}

static size_t	ft_cntletters(const char *s, size_t start, char sep)
{
	size_t	cnt;

	cnt = 0;
	while (s[start] && s[start] != sep)
	{
		start++;
		cnt++;
	}
	return (cnt);
}

static char	*ft_strmalloc(const char *s, size_t start, char sep, char	**tab)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = malloc (sizeof(char) * (ft_cntletters(s, start, sep) + 1));
	if (!p)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		return (NULL);
	}
	while (s[start] && s[start] != sep)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return ((char *)p);
}

static void	ft_init_vars(size_t *start, size_t *i, size_t *j)
{
	*start = 0;
	*j = 0;
	*i = 0;
}

char	**ft_split(char const *s, char sep)
{
	char			**tab;
	size_t			start;
	size_t			j;
	size_t			i;

	ft_init_vars(&start, &i, &j);
	tab = malloc (sizeof(char *) * (ft_wcount(s, sep) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		if (s[i] != sep && j < ft_wcount(s, sep))
		{
			start = i;
			tab[j] = ft_strmalloc(s, start, sep, tab);
			j++;
			while (s[i] && s[i] != sep)
				i++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
