/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:15:18 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/21 13:18:20 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closes(int keycode, t_game *game)
{
	if (keycode || game)
		;
	printf("closed\n");
	exit(EXIT_SUCCESS);
	mlx_destroy_window(game->mlx, game->window);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	*game;
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		perror("ERROR\nmalloc_error\n");
		return (FALSE);
	}
	game->map.movement = 0;
	check_file_extention(argc, argv, game);
	read_and_isvalid_map_check(game, argv);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map.colums * TILE_SIZE,
			game->map.rows * TILE_SIZE, "so-long");
	get_img(game);
	render_map(game);
	mlx_key_hook(game->window, what_key, game);
	mlx_hook(game->window, DELETE_EVE, DELETE_MASK, closes, game);
	mlx_loop(game->mlx);
	return (TRUE);
}
__attribute__((destructor)) // leakがないかチェック
static void
destructor()
{
	system("leaks -q so_long");
}
