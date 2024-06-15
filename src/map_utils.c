/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:27:05 by yvann             #+#    #+#             */
/*   Updated: 2024/01/16 14:44:50 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	return_error(char *message)
{
	ft_printf("Error : %s\n", message);
	return (1);
}

int	check_empty_lines(const char *buf)
{
	int	i;
	int	newline_count;

	i = 0;
	newline_count = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			newline_count++;
			if (newline_count > 1)
				return (1);
		}
		else
			newline_count = 0;
		i++;
	}
	return (0);
}

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**copy_map(char **original_map, int height, int width)
{
	int		y;
	char	**new_map;

	new_map = (char **)ft_calloc(height + 1, sizeof(char *));
	if (new_map == NULL)
		return (NULL);
	y = 0;
	while (y < height)
	{
		new_map[y] = (char *)ft_calloc(width + 2, sizeof(char));
		if (new_map[y] == NULL)
		{
			while (--y >= 0)
				free(new_map[y]);
			free(new_map);
			return (NULL);
		}
		ft_strcpy(new_map[y], original_map[y]);
		y++;
	}
	return (new_map);
}

int	is_backtrack_exit_collectibles_valid(char **map, int height, \
int width, t_game *game)
{
	char		**map_copy;
	char		**map_copy2;
	t_pos		player;

	map_copy = copy_map(map, height, width);
	map_copy2 = copy_map(map, height, width);
	if (map_copy == NULL || map_copy2 == NULL)
	{
		return_error("Error: Unable to create map copy");
		return (1);
	}
	player = research_char(map_copy, (t_pos){0, 0}, 'P', height);
	game->player_pos = player;
	if (research_exit_collectibles(map_copy, player, 'C', height) == -1)
	{
		free_map(map_copy2, height);
		return_error("Invalid map: Can't access collectibles");
		return (1);
	}
	else if (research_exit_collectibles(map_copy2, player, 'E', height) == -1)
		return (return_error("Invalid map: No path to exit"));
	return (0);
}
