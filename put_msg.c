/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:52:06 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/23 15:56:44 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	closes(t_game *game)
{
	ft_printf("\x1b[1;31mclosed\n\x1b[0m");
	ft_printf("Movement : %d\n", game->map.movement);
	mlx_destroy_window(game->mlx, game->window);
	exit(EXIT_SUCCESS);
}

void	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	ft_printf(
		"\033[0;32m█████████████████████████████████████████████████████████████████\n\
██                                                             ██\n\
██   █████     ██      ██████     ███      ██████     ██  ██   ██\n\
██  ██    ██   ██      ██        ██ ██     █    ██    ██  ██   ██\n\
██  ██         ██      █████    ██   ██    ██████     ██  ██   ██\n\
██  ██    ██   ██      ██      █████████   ██                  ██\n\
██   █████     ██████  ██████ ██       ██  ██  ███    ██  ██   ██\n\
██                                                             ██\n\
█████████████████████████████████████████████████████████████████\n\n\033[0m");
	ft_printf("MOVEMENT : %d\n", game->map.movement + 1);
	exit(EXIT_SUCCESS);
}

void	exit_msg(char *word)
{
	if (ft_strncmp(word, "wall", ft_strlen("wall")) == 0)
		ft_printf("\x1b[31mError\nMAP WALL NOT VALID\n\x1b[0m");
	if (ft_strncmp(word, "width", ft_strlen("width")) == 0)
		ft_printf("\x1b[31mError\nMAP WIDTH NOT VALID\n\x1b[0m");
	if (ft_strncmp(word, "elenotcontain", ft_strlen("elenotcontain")) == 0)
		ft_printf("\x1b[31mError\nMAP NOTCOLLECT_ELEMENT_CONTEIN\n\x1b[0m");
	if (ft_strncmp(word, "invalidele", ft_strlen("invalidele")) == 0)
		ft_printf("\x1b[31mError\nMAP ELEMENTS NOT VALID\n\x1b[0m");
	if (ft_strncmp(word, "mallocerror", ft_strlen("mallocerror")) == 0)
		ft_printf("\x1b[31mError\nMALLOC_ERROR\n\x1b[0m");
	if (ft_strncmp(word, "argc", ft_strlen("argc")) == 0)
		ft_printf("\033[31mError\nARGC INVALID\n\x1b[0m");
	if (ft_strncmp(word, "extention", ft_strlen("extention")) == 0)
		ft_printf("\033[31mError\nINVALID EXTENTION\n\x1b[0m");
	if (ft_strncmp(word, "mapnotfound", ft_strlen("mapnotfound")) == 0)
		ft_printf("\x1b[31mError\nMAP NOT FOUND\n\x1b[0m");
	if (ft_strncmp(word, "mapinvalid", ft_strlen("mapinvalid")) == 0)
		ft_printf("\x1b[31mError\nMAP INVALID\n\x1b[0m");
	if (ft_strncmp(word, "can'tgoal", ft_strlen("can'tgoal")) == 0)
		ft_printf("\x1b[31mError\nCAN'T REACH GOAL\n\x1b[0m");
	exit(EXIT_FAILURE);
}
