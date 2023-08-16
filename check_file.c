/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:23:29 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/16 10:59:01 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_file_extention(int argc,char *argv[],t_game *game)
{
    if(game)
    ;
    if(argc != CORRECT_ARGC_NUM)
    {
        ft_printf("\033[1;31m----ERROR----ARGC INVALID\n\x1b[0m");
        exit(EXIT_FAILURE);
    }
    if(ft_strnstr(argv[CORRECT_ARGC_NUM-1],EXTENSION,ft_strlen(argv[CORRECT_ARGC_NUM-1])) == NULL)
    {
        ft_printf("\033[1;31m----ERROR----INVALID EXTENTION\n\x1b[0m");
        exit(EXIT_FAILURE);
    }

}