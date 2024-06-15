/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:06:05 by ybarbot           #+#    #+#             */
/*   Updated: 2024/01/13 17:09:50 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move_player_up(game);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move_player_down(game);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move_player_left(game);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move_player_right(game);
	return (0);
}

void	cleanup(t_game *game)
{
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->empty.img)
		mlx_destroy_image(game->mlx, game->empty.img);
	if (game->collectible.img)
		mlx_destroy_image(game->mlx, game->collectible.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map, game->height);
}

void	*return_error_null(char *message)
{
	ft_printf("Error : %s\n", message);
	return (NULL);
}
