/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:34:25 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/08 15:00:26 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char  *get_next_line(int fd);
size_t	ft_gstrlen(const char *s);
char	*ft_gstrjoin(char const *s1, char const *s2);
char	*ft_gstrchr(const char *s, int c);



#endif