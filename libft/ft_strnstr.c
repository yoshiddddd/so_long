/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:55:39 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/08 15:33:28 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *bigger, const char *smaller, size_t len)
{
	unsigned long	i;

	i = 0;
	if (*smaller == '\0')
		return ((char *)bigger);
	while (i < len && *bigger != '\0')
	{
		if (ft_strncmp(bigger, smaller, ft_strlen(smaller)) == 0)
		{
			if (i + ft_strlen(smaller) > len)
				return (NULL);
			return ((char *)bigger);
		}
		bigger++;
		i++;
	}
	return (NULL);
}
// int main(void)
// {
// 		char *sp;
// 		// char * empty = (char*)"";
// 		 char haystack[30] = "aaabcabcd";
// 		puts("ft_strnstr:");
// 		sp = ft_strnstr(haystack, "cd", 8);
// 		printf("%s\n", sp);
// 			puts("strnstr:");
// 		printf("%s",strnstr(haystack, "cd", 8));
// 		// 	// sp = strnstr(s1, s2, -1);
// }