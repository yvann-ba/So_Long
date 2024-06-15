/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:53:51 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/12 00:29:14 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_up(t_game *game)
{
	if (game->map[game->player_pos.y - 1][game->player_pos.x] == '1')
		return ;
	if (game->map[game->player_pos.y - 1][game->player_pos.x] == 'C')
	{
		game->map[game->player_pos.y - 1][game->player_pos.x] = '0';
		game->collectible_count--;
	}
	if (game->map[game->player_pos.y - 1][game->player_pos.x] == 'E')
	{
		if (game->collectible_count == 0)
			close_window(game);
		return ;
	}
	game->map[game->player_pos.y][game->player_pos.x] = '0';
	game->player_pos.y--;
	game->map[game->player_pos.y][game->player_pos.x] = 'P';
	game->move_count++;
	ft_printf("Move count : %d\n", game->move_count);
}

void	move_player_down(t_game *game)
{
	if (game->map[game->player_pos.y + 1][game->player_pos.x] == '1')
		return ;
	if (game->map[game->player_pos.y + 1][game->player_pos.x] == 'C')
	{
		game->map[game->player_pos.y + 1][game->player_pos.x] = '0';
		game->collectible_count--;
	}
	if (game->map[game->player_pos.y + 1][game->player_pos.x] == 'E')
	{
		if (game->collectible_count == 0)
			close_window(game);
		return ;
	}
	game->map[game->player_pos.y][game->player_pos.x] = '0';
	game->player_pos.y++;
	game->map[game->player_pos.y][game->player_pos.x] = 'P';
	game->move_count++;
	ft_printf("Move count : %d\n", game->move_count);
}

void	move_player_left(t_game *game)
{
	if (game->map[game->player_pos.y][game->player_pos.x - 1] == '1')
		return ;
	if (game->map[game->player_pos.y][game->player_pos.x - 1] == 'C')
	{
		game->map[game->player_pos.y][game->player_pos.x - 1] = '0';
		game->collectible_count--;
	}
	if (game->map[game->player_pos.y][game->player_pos.x - 1] == 'E')
	{
		if (game->collectible_count == 0)
			close_window(game);
		return ;
	}
	game->map[game->player_pos.y][game->player_pos.x] = '0';
	game->player_pos.x--;
	game->map[game->player_pos.y][game->player_pos.x] = 'P';
	game->move_count++;
	ft_printf("Move count : %d\n", game->move_count);
}

void	move_player_right(t_game *game)
{
	if (game->map[game->player_pos.y][game->player_pos.x + 1] == '1')
		return ;
	if (game->map[game->player_pos.y][game->player_pos.x + 1] == 'C')
	{
		game->map[game->player_pos.y][game->player_pos.x + 1] = '0';
		game->collectible_count--;
	}
	if (game->map[game->player_pos.y][game->player_pos.x + 1] == 'E')
	{
		if (game->collectible_count == 0)
			close_window(game);
		return ;
	}
	game->map[game->player_pos.y][game->player_pos.x] = '0';
	game->player_pos.x++;
	game->map[game->player_pos.y][game->player_pos.x] = 'P';
	game->move_count++;
	ft_printf("Move count : %d\n", game->move_count);
}
