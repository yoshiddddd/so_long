/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:38:27 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/08 15:27:50 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count2(const char *c, const char *c2)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	i = ft_strlen(c);
	k = ft_strlen(c2);
	return (i + k);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*concat_s;
	int		i;

	i = 0;
	len = ft_count2(s1, s2);
	concat_s = (char *)malloc(sizeof(char) * len + 1);
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
// int	main(void)
// {
// 	char *s;
// 	s = ft_strjoin(NULL, NULL);

// 	printf("%s", s);
// }