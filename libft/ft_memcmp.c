/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:23:42 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/01 16:22:30 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (0);
	while (n > 0)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		st1++;
		st2++;
		n--;
	}
	return (0);
}

// int	main(void)
// {
//  char s[] = {-128, 0, 127, 0};
//         // char sCpy[] = {-128, 0, 127, 0};
//         // char s2[] = {0, 0, 127, 0};
//         // char s3[] = {0, 0, 42, 0};
// 		printf("%d",memcmp(s, NULL, 2));
// }