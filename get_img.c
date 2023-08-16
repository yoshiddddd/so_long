/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:19:09 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/16 18:56:15 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_img(t_game *game)
{
	game->map.player.img_ptr = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH,
			&game->map.player.x, &game->map.player.y);
	game->map.wall.img_ptr = mlx_xpm_file_to_image(game->mlx, WALL_PATH,
			&game->map.wall.x, &game->map.wall.y);
	game->map.item.img_ptr = mlx_xpm_file_to_image(game->mlx, ITEM_PATH,
			&game->map.item.x, &game->map.item.y);
	game->map.floor.img_ptr = mlx_xpm_file_to_image(game->mlx, FLOOR_PATH,
			&game->map.floor.x, &game->map.floor.y);
	game->map.goal.img_ptr = mlx_xpm_file_to_image(game->mlx, GOAL_PATH,
			&game->map.goal.x, &game->map.goal.y);
}
