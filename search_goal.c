/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_goal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:17:46 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/20 14:51:09 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void dfs(int x,int y , t_game *game)
{

    
    if(x<0 ||game->map.rows<x || y<0 || game->map.colums<y || game->map.all[x][y] == '1')
        return ;
    if(game->map.reach[x][y] == true)
        return ;

    game->map.reach[x][y] = true;
    dfs(x+1,y,game);
    dfs(x-1,y,game);
    dfs(x,y+1,game);
    dfs(x,y-1,game);
}

bool is_goal_true(t_game *game)
{
    int i;
    int j;

    i = 0;
    while(i<game->map.rows)
    {
        j = 0;
        while(j < game->map.colums)
        {
            if(game->map.all[i][j] == 'E' || game->map.all[i][j] == 'C')
            {
                if(game->map.reach[i][j] == false)
                    return false;
            }
            j++;
        
        }
        i++;
    }
    return true;
}

void research_init(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    game->map.reach = (bool **)malloc(sizeof(bool *) * game->map.rows);
    
    while(i<game->map.rows)
    {
        game->map.reach[i] = (bool *)malloc(sizeof(bool)*game->map.colums);
        while(j<game->map.colums)
        {
            game->map.reach[i][j] = false;
            j++;
        }
        i++;
    }
}

void search_goal(t_game *game)
{
    int i;
    int j;

    int start_x;
    int start_y;
    i = 0;
    start_x = 0;
    start_y = 0;
    research_init(game);
    while(i<game->map.rows)
    {
    j = 0;
        while(j<game->map.colums)
        {
            if(game->map.all[i][j] == 'P')
            {
                start_x = i;
                start_y = j;
                break;
            }
        j++;
        }
    i++;
    }
    dfs(start_x,start_y,game);
    if(is_goal_true(game) == false)
    {
		ft_printf("\x1b[31mERROR\nCAN'T REACH GOAL\n\x1b[0m");
        exit(EXIT_FAILURE);
    }
}
