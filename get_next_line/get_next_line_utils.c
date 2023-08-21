/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:35:34 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/21 19:24:07 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gstrlen(const char *s)
{
	size_t	num;

	if (!s)
		return (0);
	num = 0;
	while (s[num] != '\0')
		num++;
	return (num);
}

char	*ft_gstrjoin(char const *s1, char const *s2)
{
	char	*concat_s;
	int		i;

	i = 0;
	concat_s = (char *)malloc(sizeof(char) * ft_gstrlen(s1) + ft_gstrlen(s2)
			+ 1);
	if (concat_s == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		while (*s1 != '\0')
			concat_s[i++] = *s1++;
	}
	if (s2 != NULL)
	{
		while (*s2 != '\0')
			concat_s[i++] = *s2++;
	}
	concat_s[i] = '\0';
	return (concat_s);
}

char	*ft_gstrchr(const char *s, int c)
{
	char	ch;
	char	*s2;

	if (!s)
		return (NULL);
	ch = (char)c;
	s2 = (char *)s;
	while (*s2 != '\0')
	{
		if (*s2 == ch)
			return (s2);
		s2++;
	}
	return (NULL);
}
