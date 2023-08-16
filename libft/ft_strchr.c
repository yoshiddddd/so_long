/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:30:16 by yoshidakazu       #+#    #+#             */
/*   Updated: 2023/08/08 15:27:32 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (1)
	{
		if (*s == (char)c)
			break ;
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

// int main(void)
// {
//  		char s[] = "tripouille";
// 	char *p;

// 	p = ft_strchr(s, 't' + 256);

// 	printf("%s",p);

// }