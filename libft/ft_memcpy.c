/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:26:58 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/02 16:29:22 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dest);
}

// int	main(void)
// {
// 	char str[100] = "asdfg";
//   char  *t = NULL;

//   ft_memcpy(str, NULL, 3);
// //   memcpy(NULL, str, 3);
//   printf("ft_memcpy():  str = %s, t = %s\n", str, t);
// }