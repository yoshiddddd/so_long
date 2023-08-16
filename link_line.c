/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:54:23 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/16 18:54:51 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*link_line(char *s1, char *s2)
{
	char	*str;
	char	*str_start;
	char	*s1_start;
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
