/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:53:18 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/16 19:08:35 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
}

void	p_move(t_game *game, int next_x, int next_y)
{
	int	last_x;
	int	last_y;

	last_x = game->map.player.p_position_x;
	last_y = game->map.player.p_position_y;
	if (game->map.all[next_y][next_x] == GOAL && game->map.item.num == 0)
		end_game(game);
	if (game->map.all[next_y][next_x] == FLOOR
		|| game->map.all[next_y][next_x] == ITEM)
	{
		if (game->map.all[next_y][next_x] == ITEM)
			game->map.item.num--;
		game->map.all[last_y][last_x] = FLOOR;
		game->map.all[next_y][next_x] = PLAYER;
		game->map.player.p_position_x = next_x;
		game->map.player.p_position_y = next_y;
		render_map(game);
	}
}

int	what_key(int keycode, t_game *game)
{
	int	now_x;
	int	now_y;

	now_x = game->map.player.p_position_x;
	now_y = game->map.player.p_position_y;
	if (keycode == UP)
		p_move(game, now_x, now_y - 1);
	if (keycode == DOWN)
		p_move(game, now_x, now_y + 1);
	if (keycode == RIGHT)
		p_move(game, now_x + 1, now_y);
	if (keycode == LEFT)
		p_move(game, now_x - 1, now_y);
	return (0);
}
