/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:26:59 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/20 14:58:48 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
// #include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdbool.h>
# include <string.h>

# define FALSE 1
# define TRUE 0

# define CORRECT_ARGC_NUM 2
# define EXTENSION ".ber"
# define LINE_NULL 1
# define INVALID_FD -1

# define PLAYER 'P'
# define ITEM 'C'
# define FLOOR '0'
# define GOAL 'E'
# define WALL '1'

# define DELETE_EVE 17
# define DELETE_MASK 1L << 17

# define PLAYER_PATH "./textures/player.xpm"
# define ITEM_PATH "./textures/coins.xpm"
# define WALL_PATH "./textures/background.xpm"
# define GOAL_PATH "./textures/exit.xpm"
# define FLOOR_PATH "./textures/empty.xpm"
# define DAMAGE_PATH "./textures/damage.xpm"
# define DAHARA_PATH "./textures/keigo.xpm"

# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0

# define TILE_SIZE 32

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_element
{
	void		*img_ptr;
	int			num;
	int			x;
	int			y;
	int			p_position_x;
	int			p_position_y;
	int 		g_position_x;
	int 		g_position_y;
}				t_element;

typedef struct s_map
{
	char		**all;
	int			rows;
	int			colums;
	int			invalid_element;
	int			movement;
	bool 		**reach;
	t_element	player;
	t_element	wall;
	t_element	item;
	t_element	goal;
	t_element	floor;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		map;

}				t_game;

void			check_file_extention(int argc, char *argv[], t_game *game);
void			read_and_isvalid_map_check(t_game *game, char *argv[]);
void			get_img(t_game *game);
void			render_map(t_game *game);
int				what_key(int keycode, t_game *game);
void			isvalid_map_check(t_game *game, char *argv[]);
void			free_and_exit_msg(t_game *game, char *word);
void			free_double(t_game *game);
char			*link_line(char *s1, char *s2);
void	map_error_check(t_game *game);
void	map_isvalid_elements(t_game *game);
void search_goal(t_game *game);
#endif