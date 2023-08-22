/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seach_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:29:25 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/22 23:30:33 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_is_wall_check(t_game *game)
{
	char	**map;
	int		i;

	i = 0;
	map = game->map.all;
	while (map[game->map.rows - 1][i])
	{
		if (map[0][i] != WALL || map[game->map.rows - 1][i] != WALL)
			exit_msg("wall");
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != WALL || map[i][game->map.colums - 1] != WALL)
			exit_msg("wall");
		i++;
	}
}

void	map_error_check(t_game *game)
{
	size_t	i;

	game->map.colums = (int)ft_strlen(game->map.all[0]);
	i = 0;
	while (game->map.all[i] != NULL)
	{
		if (game->map.colums != (int)ft_strlen(game->map.all[i]))
			exit_msg("width");
		i++;
	}
	map_is_wall_check(game);
}

void	search_element_num(char *map, t_game *game)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == PLAYER)
			game->map.player.num++;
		else if (map[i] == ITEM)
			game->map.item.num++;
		else if (map[i] == GOAL)
			game->map.goal.num++;
		else if (map[i] == FLOOR)
			game->map.floor.num++;
		else if (!(map[i] == WALL))
			game->map.invalid_element++;
		i++;
	}
}

void	check_elements(t_game *game)
{
	int		i;
	char	**map;

	i = 0;
	map = game->map.all;
	while (map[i])
	{
		search_element_num(map[i], game);
		i++;
	}
	if (game->map.invalid_element > 0)
		exit_msg("elenotcontain");
}

void	map_isvalid_elements(t_game *game)
{
	check_elements(game);
	if (game->map.player.num != 1 || game->map.item.num < 1
		|| game->map.goal.num != 1)
		exit_msg("invalidele");
}
