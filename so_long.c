/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:15:18 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/16 11:24:57 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "so_long.h"

int	closes(int keycode, t_game *vars)
{
    if(keycode)
    ;
	mlx_destroy_window(vars->mlx, vars->window);
	return (0);
}

int main(int argc, char *argv[])
{
    t_game *game;
    game = (t_game *)malloc(sizeof(t_game));
    if(!game)
    {
        perror("----malloc_error------\n");
        return FALSE;
    }
    check_file_extention(argc,argv,game);

    isvalid_map_check(game,argv);
    game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx,game->map.colums*TILE_SIZE , game->map.rows*TILE_SIZE,"so-long");
    get_img(game);

    render_map(game);
    mlx_hook(game->window, DELETE_EVE, DELETE_MASK, closes, game);
    mlx_key_hook(game->window , what_key,game );
    mlx_loop(game->mlx);
    return 0;
}
__attribute__((destructor)) // leakがないかチェック
static void destructor() {
    system("leaks -q so_long");
}
