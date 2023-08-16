/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:27:23 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/08 14:28:04 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (!dst || !src)
		return (NULL);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else if (d > s)
	{
		d += len - 1;
		s += len - 1;
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}

// int	main(void)
// {
// 	char *c;
// 	c="aa";
// 	ft_memmove(c,NULL,3);
// 	printf("%s",c);
// }