/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:36:00 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/09 10:03:16 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*full_s;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	full_s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (full_s == NULL)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		full_s[i] = s1[i];
	j = -1;
	while (++j < ft_strlen(s2))
		full_s[i++] = s2[j];
	full_s[i] = '\0';
	return (full_s);
}
