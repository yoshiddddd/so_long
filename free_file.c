/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:52:06 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/16 18:52:27 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.all[i])
	{
		free(game->map.all[i]);
		i++;
	}
	free(game->map.all);
}

void	free_and_exit_msg(t_game *game, char *word)
{
	// free_double(game);
	if (game)
		;
	if (ft_strncmp(word, "wall", ft_strlen("wall")) == 0)
		ft_printf("\x1b[31mERROR\nMAP WALL NOT VALID\n\x1b[0m");
	if (ft_strncmp(word, "width", ft_strlen("width")) == 0)
		ft_printf("\x1b[31mERROR\nMAP WIDTH NOT VALID\n\x1b[0m");
	if (ft_strncmp(word, "elenotcontain", ft_strlen("elenotcontain")) == 0)
		ft_printf("\x1b[31mERROR\nMAP NOTCOLLECT_ELEMENT_CONTEIN\n\x1b[0m");
	if (ft_strncmp(word, "invalidele", ft_strlen("invalidele")) == 0)
		ft_printf("\x1b[31mERROR\nMAP ELEMENTS NOT VALID\n\x1b[0m");
	exit(EXIT_FAILURE);
}
