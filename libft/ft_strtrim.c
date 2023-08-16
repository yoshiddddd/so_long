/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:59:53 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/08 15:33:42 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_frontcheck(char const *s1, char const *set)
{
	int	i;
	int	flag;

	flag = 1;
	while (*s1 != '\0')
	{
		i = 0;
		while (set[i] != '\0')
		{
			if (*s1 == set[i])
			{
				flag *= -1;
				break ;
			}
			i++;
		}
		if (flag == 1)
			break ;
		flag *= -1;
		s1++;
	}
	return ((char *)s1);
}

static size_t	ft_backcheck(char *front, char const *set, size_t nowlen,
		size_t subcount)
{
	int	i;
	int	flag;

	flag = 1;
	if (nowlen != 0)
		nowlen -= 1;
	while (nowlen != 0)
	{
		i = 0;
		while (set[i] != '\0')
		{
			if (front[nowlen] == set[i])
			{
				flag *= -1;
				nowlen--;
				break ;
			}
			i++;
		}
		if (flag == 1)
			break ;
		flag *= -1;
		subcount++;
	}
	return (subcount);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	char	*front;
	size_t	count;
	size_t	subcount;
	size_t	nowlen;

	if (s1 == NULL || set == NULL)
		return (NULL);
	subcount = 0;
	front = ft_frontcheck(s1, set);
	nowlen = ft_strlen(front);
	count = ft_backcheck(front, set, nowlen, subcount);
	ans = (char *)malloc(sizeof(char) * nowlen - count + 1);
	if (ans == NULL)
		return (NULL);
	ft_strlcpy(ans, front, nowlen - count + 1);
	return (ans);
}

// int	main(void)
// {
// 	char *test;
// 	test = ft_strtrim("hello world", "hello");
// 	// printf("%lu", strlen(test));
// 	printf("%s\n", test);
// }