/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvann <yvann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:27:17 by yvann             #+#    #+#             */
/*   Updated: 2023/11/12 18:48:49 by yvann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

static void	ft_rev_str_tab(char *str, size_t size)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = tmp;
		i++;
	}
}

static char	*ft_malloc_str(int n)
{
	size_t	i;
	char	*str;

	if (n == 0)
	{
		str = ft_calloc(2, sizeof(*str));
		str[0] = '0';
		return (str);
	}
	i = 0;
	if (n < 0)
	{
		n = ft_abs(n);
		i++;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	str = ft_calloc(i + 1, sizeof(*str));
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		is_neg;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_neg = (n < 0);
	str = ft_malloc_str(n);
	if (!str)
		return (NULL);
	if (n == 0)
		return (str);
	i = 0;
	n = ft_abs(n);
	while (n != 0)
	{
		str[i++] = (n % 10) + '0';
		n = n / 10;
	}
	if (is_neg)
		str[i++] = '-';
	str[i] = '\0';
	ft_rev_str_tab(str, ft_strlen(str));
	return (str);
}
