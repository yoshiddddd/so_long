/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:15:18 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/23 17:43:44 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		exit_msg("mallocerror");
	init_game(game);
	check_file_extention(argc, argv);
	read_and_isvalid_map_check(game, argv);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map.colums * TILE_SIZE,
			game->map.rows * TILE_SIZE, "so-long");
	get_img(game);
	render_map(game);
	mlx_key_hook(game->window, what_key, game);
	mlx_hook(game->window, DELETE_EVE, 1L << 17, closes, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
// __attribute__((destructor))
// static void
// destructor()
// {
// 	system("leaks -q so_long");
// }
