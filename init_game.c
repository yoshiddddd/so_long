/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:27:37 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/23 14:26:09 by kyoshida         ###   ########.fr       */
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
	game->map.floor.num = 0;
	game->map.item.num = 0;
}
