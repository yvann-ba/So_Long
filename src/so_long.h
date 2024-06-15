/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:11:32 by yvann             #+#    #+#             */
/*   Updated: 2024/01/16 14:53:02 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ESC 0xff1b
# define KEY_UP 0xff52
# define KEY_DOWN 0xff54
# define KEY_LEFT 0xff51
# define KEY_RIGHT 0xff53
# define KEY_W 0x0077
# define KEY_S 0x0073
# define KEY_A 0x0061
# define KEY_D 0x0064

# include <stdio.h>
# include <stdlib.h>
# include "../libs/Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include "../libs/mlx/mlx.h"

typedef struct s_sprite
{
	void	*img;
}	t_sprite;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_sprite	player;
	t_sprite	wall;
	t_sprite	empty;
	t_sprite	collectible;
	t_sprite	exit;
	char		**map;
	int			width;
	int			height;
	void		*img;
	t_pos		player_pos;
	int			collectible_count;
	int			move_count;
}	t_game;

int		return_error(char *message);
void	*return_error_null(char *message);

int		draw_map(void *game);
void	draw_sprite(t_game *game, char c, int x, int y);
void	load_sprites(t_game *game);
void	cleanup(t_game *game);
int		check_empty_lines(const char *buf);
int		can_go_position(char **map, t_pos player, t_pos dest);
int		check_file_extension(char *file);
int		init_graphics(t_game *game);
void	free_map(char **map, int height);
char	**get_map(char *argv_one, t_game *game);
int		is_map_valid(char **map, int height, int width, t_game *game);
t_pos	research_char(char **tab, t_pos start, char c, int height);
int		is_backtrack_exit_collectibles_valid(char **map, int height, \
int width, t_game *game);
int		research_exit_collectibles(char **map, t_pos player, \
char c, int height);
char	**copy_map(char **original_map, int height, int width);
int		count_elements(char **map, int height, int width, char element);
int		close_window(t_game *game);
int		key_press(int keycode, t_game *game);
void	move_player_up(t_game *game);
void	move_player_down(t_game *game);
void	move_player_left(t_game *game);
void	move_player_right(t_game *game);

#endif