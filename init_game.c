/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:27:37 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/24 13:08:23 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->map.colums = 0;
	game->map.rows = 0;
	game->map.invalid_element = 0;
	game->map.movement = 0;
	game->map.player.num = 0;
	game->map.goal.num = 0;
	game->map.wall.num = 0;
	game->map.item.num = 0;
}
