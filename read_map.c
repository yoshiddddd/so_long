/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:50:59 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/16 18:51:43 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_file(t_game *game, int fd)
{
	char	*map_line;
	char	*tmp_line;

	while (LINE_NULL)
	{
		map_line = get_next_line(fd);
		if (map_line == NULL || map_line[0] == '\n')
			break ;
		tmp_line = link_line(tmp_line, map_line);
		if (tmp_line == NULL)
		{
			free(map_line);
			ft_printf("\x1b[31mERROR\nMALLOC_FAILD\n\x1b[0m");
			exit(EXIT_FAILURE);
		}
		free(map_line);
		game->map.rows++;
	}
	free(map_line);
	close(fd);
	return (tmp_line);
}

void	isvalid_map_check(t_game *game, char *argv[])
{
	char	*tmp_line;
	int		fd;

	tmp_line = NULL;
	fd = open(argv[CORRECT_ARGC_NUM - 1], O_RDONLY);
	if (fd == INVALID_FD)
	{
		ft_printf("\x1b[31mERROR\nMAP NOT FOUND\n\x1b[0m");
		exit(EXIT_FAILURE);
	}
	tmp_line = read_file(game, fd);
	game->map.all = ft_split(tmp_line, '\n');
	if (game->map.all == NULL)
	{
		ft_printf("\x1b[31mERROR\nMAP INVALID\n\x1b[0m");
		exit(EXIT_FAILURE);
	}
	free(tmp_line);
	map_error_check(game);
	map_isvalid_elements(game);
}
