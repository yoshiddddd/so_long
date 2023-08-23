/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_isvalid_map_check.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:50:59 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/23 10:56:56 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_file(t_game *game, int fd)
{
	char	*map_line;
	char	*tmp_line;

	tmp_line = NULL;
	while (LINE_NULL)
	{
		map_line = get_next_line(fd);
		if (map_line == NULL || map_line[0] == '\n')
			break ;
		tmp_line = link_line(tmp_line, map_line);
		if (tmp_line == NULL)
			exit_msg("mallocerror");
		free(map_line);
		game->map.rows++;
	}
	free(map_line);
	close(fd);
	return (tmp_line);
}

void	read_and_isvalid_map_check(t_game *game, char *argv[])
{
	char	*tmp_line;
	int		fd;

	fd = open(argv[CORRECT_ARGC_NUM - 1], O_RDONLY);
	if (fd == INVALID_FD)
		exit_msg("mapnotfound");
	tmp_line = read_file(game, fd);
	game->map.all = ft_split(tmp_line, '\n');
	if (game->map.all == NULL)
		exit_msg("mapinvalid");
	free(tmp_line);
	map_error_check(game);
	map_isvalid_elements(game);
	search_goal(game);
}
