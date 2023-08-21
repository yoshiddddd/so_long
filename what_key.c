/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:53:18 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/21 09:33:56 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	ft_printf(		
"\033[0;32m███████████████████████████████████████████████████████████████\n\
██                                                           ██\n\
██   ████    █        ██████      █      ██████     ██  ██   ██\n\
██  █    █   █        █          █ █     █    ██    ██  ██   ██\n\
██  █        █        █████     █   █    ██████     ██  ██   ██\n\
██  █    █   █        █        ███████   ██                  ██\n\
██   ████    ██████   ██████  █       █  ██  ███    ██  ██   ██\n\
██                                                           ██\n\
███████████████████████████████████████████████████████████████\n\n\033[0m");
	ft_printf("MOVEMENT : %d\n",game->map.movement++);
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
		|| game->map.all[next_y][next_x] == ITEM || game->map.all[next_y][next_x] == GOAL)
	{
		if (game->map.all[next_y][next_x] == ITEM)
			game->map.item.num--;

		if(last_x == game->map.goal.g_position_x&&last_y == game->map.goal.g_position_y)
			game->map.all[last_y][last_x] = GOAL;			
		else
			game->map.all[last_y][last_x] = FLOOR;

		game->map.all[next_y][next_x] = PLAYER;
		game->map.player.p_position_x = next_x;
		game->map.player.p_position_y = next_y;
		game->map.movement++;
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
