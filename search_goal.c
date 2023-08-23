/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_goal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:17:46 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/23 15:19:34 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dfs(int x, int y, t_game *game)
{
	if (x <= 0 || game->map.rows <= x || y <= 0 || game->map.colums <= y
		|| game->map.all[x][y] == WALL)
		return ;
	if (game->map.reach[x][y] == true)
		return ;
	game->map.reach[x][y] = true;
	dfs(x + 1, y, game);
	dfs(x - 1, y, game);
	dfs(x, y + 1, game);
	dfs(x, y - 1, game);
}

static bool	is_goal_true(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.colums)
		{
			if (game->map.all[i][j] == GOAL || game->map.all[i][j] == ITEM)
			{
				if (game->map.reach[i][j] == false)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

static void	research_init(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->map.reach = (bool **)malloc(sizeof(bool *) * game->map.rows);
	if (!game->map.reach)
		exit_msg("mallocerror");
	while (i < game->map.rows)
	{
		game->map.reach[i] = (bool *)malloc(sizeof(bool) * game->map.colums);
		if (!game->map.reach)
			exit_msg("mallocerror");
		j = 0;
		while (j < game->map.colums)
		{
			game->map.reach[i][j] = false;
			j++;
		}
		i++;
	}
}

void	search_goal(t_game *game)
{
	int	i;
	int	j;
	int	start_x;
	int	start_y;

	i = 0;
	research_init(game);
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.colums)
		{
			if (game->map.all[i][j] == PLAYER)
			{
				start_x = i;
				start_y = j;
				break ;
			}
			j++;
		}
		i++;
	}
	dfs(start_x, start_y, game);
	if (is_goal_true(game) == false)
		exit_msg("can'tgoal");
}
