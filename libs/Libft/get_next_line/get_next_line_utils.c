/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:09:56 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/16 12:19:26 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft.h"

char	*handle_line(char **backup)
{
	char	*line;
	char	*line_end;
	char	*new_backup;

	line = create_new_line(backup);
	line_end = ft_strchr(*backup, '\n');
	if (line_end != NULL && *(line_end + 1) != '\0')
	{
		new_backup = ft_strdup(line_end + 1);
		free(*backup);
		*backup = new_backup;
	}
	else
	{
		free(*backup);
		*backup = NULL;
	}
	return (line);
}
