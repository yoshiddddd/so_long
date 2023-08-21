/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:23:29 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/21 15:31:28 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_extention(int argc, char *argv[])
{
	if (argc != CORRECT_ARGC_NUM)
		exit_msg("argc");
	if (ft_strnstr(argv[CORRECT_ARGC_NUM - 1], EXTENSION,
			ft_strlen(argv[CORRECT_ARGC_NUM - 1])) == NULL)
		exit_msg("extention");
}
