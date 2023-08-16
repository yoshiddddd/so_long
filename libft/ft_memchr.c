/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:01:38 by kyoshida          #+#    #+#             */
/*   Updated: 2023/05/30 19:56:28 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	c2;

	s2 = (unsigned char *)s;
	c2 = (unsigned char)c;
	if (!s2)
		return (NULL);
	while (n > 0)
	{
		if (*s2 == c2)
			return (s2);
		s2++;
		n--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char s[] = {0, 1, 2 ,3 ,4 ,5};	char *p,*p2;

// 	p = ft_memchr(s, 2+256, 3);
// 	p2 = memchr(s, 2+256, 3);
// 	printf("検索文字は文字列の%ld番目\n", p - s);
// 	// printf("%d",&p2);

// 	return (0);
// }