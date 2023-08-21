/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:32:33 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/21 19:23:15 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*sub_s1;
	unsigned char	*sub_s2;

	sub_s1 = (unsigned char *)s1;
	sub_s2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (0);
	while (n > 0)
	{
		if (*sub_s1 != *sub_s2)
			return (*sub_s1 - *sub_s2);
		if (*sub_s2 == '\0' || *sub_s1 == '\0')
			break ;
		n--;
		sub_s1++;
		sub_s2++;
	}
	return (0);
}
