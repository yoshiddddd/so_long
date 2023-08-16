/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:41:14 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/08 15:33:09 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	k;
	size_t	num;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (size + s_len);
	num = size - d_len - 1;
	k = 0;
	while (k < num && src[k] != '\0')
	{
		dest[d_len + k] = src[k];
		k++;
	}
	dest[k + d_len] = '\0';
	return (s_len + d_len);
}

// int	main(void)
// {
// 	size_t result1 = strlcat(NULL, NULL, 3);
// 	printf("ft:%zu\n", result1);
// }