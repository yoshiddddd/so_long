/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:31:35 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/08 15:33:22 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	addOne(unsigned int i, char c)
// {
// 	return (i + c);
// }
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	i;
	char	*ans;

	s_len = ft_strlen(s);
	if (!s ||!f)
		return (NULL);
	ans = (char *)malloc(sizeof(char) * s_len + 1);
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		ans[i] = f(i, s[i]);
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

// int	main(void)
// {
// 	char *s = ft_strmapi("1234", addOne);

// 	printf("%s", s);
// }