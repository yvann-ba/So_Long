/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:08:50 by ybarbot           #+#    #+#             */
/*   Updated: 2023/11/10 11:26:40 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size == 0 && dst == NULL)
		return (0);
	i = 0;
	while (dst[i] && i < size)
		i++;
	j = 0;
	if (size > 0)
	{
		while (src[j] && i + j < size - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen((char *)src));
}
