/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:29:25 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/15 23:56:07 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void free_double(t_game *game)
{
    int i;

    i = 0;
    while (game->map.all[i])
    {
        free(game->map.all[i]);
        i++;
    }
    free(game->map.all);
}

void free_and_exit_msg(t_game *game , char *word)
{
    free_double(game);
if (ft_strncmp(word, "wall" ,ft_strlen("wall")) == 0)
    ft_printf("\x1b[31m-----ELLOR-----MAP WALL NOT VALID\n\x1b[0m");
if (ft_strncmp(word, "width",ft_strlen("width")) == 0)
    ft_printf("\x1b[31m-----ELLOR-----MAP WIDTH NOT VALID\n\x1b[0m");
if (ft_strncmp(word, "elenotcontain",ft_strlen("elenotcontain")) == 0)
    ft_printf("\x1b[31m-----ELLOR-----MAP NOTCOLLECT_ELEMENT_CONTEIN\n\x1b[0m");
if (ft_strncmp(word, "invalidele",ft_strlen("invalidele")) == 0)
    ft_printf("\x1b[31m-----ELLOR-----MAP ELEMENTS NOT VALID\n\x1b[0m");

    exit(EXIT_FAILURE);
}

void map_is_wall_check(t_game *game)
{
    char **map;
    int i;
    i = 0;
    map = game->map.all;
    while(map[game->map.rows-1][i])
    {
        if(map[0][i]!=WALL || map[game->map.rows-1][i]!=WALL)
            free_and_exit_msg(game , "wall");
        i++;
    }
    i = 0;
    while(map[i])
    {
        if(map[i][0]!=WALL || map[i][game->map.colums-1]!=WALL)
            free_and_exit_msg(game , "wall");
        i++;
    }
}

void map_error_check(t_game *game)
{
    size_t i;
    game->map.colums = ft_strlen(game->map.all[0]);
    i = 0;
    while(game->map.all[i]!=NULL)
    {
        if(game->map.colums != (int)ft_strlen(game->map.all[i]))
            free_and_exit_msg(game,"width");
        i++;
    }
    map_is_wall_check(game);
}
static char	*link_line(char *s1, char *s2)
{
	char	*str;
	char	*str_start;
    char *s1_start;
	size_t	size;

	if (!s1 && !s2)
		return (NULL);
    s1_start = s1;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	str_start = str;
	while (s1 != NULL && *s1)
		*str++ = *s1++;
	while (s2 != NULL && *s2)
		*str++ = *s2++;
	*str = 0;
	str = str_start;
	free(s1_start);
	return (str_start);
}
void search_element_num(char *map,t_game *game)
{
    int i;

    i = 0;
    while(map[i])
    {
        if(map[i] == PLAYER)
            game->map.player.num++;
        else if(map[i] == ITEM)
            game->map.item.num++;
        else if(map[i] == GOAL)
            game->map.goal.num++;
        else if(map[i] == FLOOR)
            game->map.floor.num++;
        else if(!(map[i] == WALL))
            game->map.invalid_element++;
        i++;

    }
}

void  check_elements(t_game *game)
{
    int i;
    char **map;
    i = 0;
    map = game->map.all;
    while(map[i])
    {
        search_element_num(map[i],game);
        i++;
    }
    if(game->map.invalid_element > 0 )
        free_and_exit_msg(game,"elenotcontain");
}

void map_isvalid_elements(t_game *game)
{

    check_elements(game);
    if(game->map.player.num != 1 || game->map.item.num < 1 || game->map.goal.num != 1 || game->map.floor.num < 1)
        free_and_exit_msg(game,"invalidele");
}

void isvalid_map_check(t_game *game, char *argv[])
{
    char *map_line;
    char *tmp_line;
    int fd;
    tmp_line = NULL;
    fd = open(argv[CORRECT_ARGC_NUM-1],O_RDONLY);
    if(fd == INVALID_FD)
    {
        ft_printf("\x1b[31m-----ELLOR-----MAP NOT FOUND\n\x1b[0m");
        exit(EXIT_FAILURE);
    }
    while(LINE_NULL)
    {
        map_line = get_next_line(fd);
        if(map_line ==NULL || map_line[0] == '\n')
            break;
        tmp_line =link_line(tmp_line,map_line);
        if(tmp_line == NULL)
        {
            free(map_line);
            ft_printf("\x1b[31m-----ELLOR----- MALLOC_FAILD\n\x1b[0m");
            exit(EXIT_FAILURE);
        }
        free(map_line);
        game->map.rows++;
    }
    free(map_line);
    close(fd);
    game->map.all = ft_split(tmp_line,'\n');
    if(game->map.all == NULL)
    {
        ft_printf("\x1b[31m-----ELLOR----- MAP INVALID\n\x1b[0m");
        
        exit(EXIT_FAILURE);
    }
    free(tmp_line);
    map_error_check(game);
    map_isvalid_elements(game);

}