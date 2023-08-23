/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:29:45 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/23 10:40:21 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_game *game, int x_num, int y_num)
{
	if (game->map.all[y_num][x_num] == PLAYER)
	{
		game->map.player.p_position_x = x_num;
		game->map.player.p_position_y = y_num;
		mlx_put_image_to_window(game->mlx, game->window,
			game->map.player.img_ptr, x_num * game->map.player.x, y_num
			* game->map.player.y);
	}
	if (game->map.all[y_num][x_num] == ITEM)
		mlx_put_image_to_window(game->mlx, game->window, game->map.item.img_ptr,
			x_num * game->map.item.x, y_num * game->map.item.y);
	if (game->map.all[y_num][x_num] == GOAL)
	{
		game->map.goal.g_position_x = x_num;
		game->map.goal.g_position_y = y_num;
		mlx_put_image_to_window(game->mlx, game->window, game->map.goal.img_ptr,
			x_num * game->map.goal.x, y_num * game->map.goal.y);
	}
	if (game->map.all[y_num][x_num] == WALL)
		mlx_put_image_to_window(game->mlx, game->window, game->map.wall.img_ptr,
			x_num * game->map.wall.x, y_num * game->map.wall.y);
	if (game->map.all[y_num][x_num] == FLOOR)
		mlx_put_image_to_window(game->mlx, game->window,
			game->map.floor.img_ptr, x_num * game->map.floor.x, y_num
			* game->map.floor.y);
}

static void	put_movement_num(t_game *game)
{
	char	*movenum;
	char	*output;

	movenum = ft_itoa(game->map.movement);
	output = ft_strjoin("MOVEMENTS : ", movenum);
	mlx_string_put(game->mlx, game->window, 20, 5, 1, output);
	free(movenum);
	free(output);
}

void	render_map(t_game *game)
{
	int	x_coord;
	int	y_coord;

	y_coord = 0;
	while (y_coord < game->map.rows)
	{
		x_coord = 0;
		while (x_coord < game->map.colums)
		{
			put_image(game, x_coord, y_coord);
			x_coord++;
		}
		y_coord++;
	}
	put_movement_num(game);
}
