/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:46:39 by kyoshida          #+#    #+#             */
/*   Updated: 2023/05/30 20:20:00 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c;

	ptr = (unsigned char *)buf;
	c = (unsigned char)ch;
	if (!buf)
		return (NULL);
	while (n > 0)
	{
		*ptr++ = c;
		n--;
	}
	return (buf);
}

// int main(void)
// {
// 	char buf[] = "ABCDEFGHIJ";

// 	//先頭から2バイト進めた位置に「１」を3バイト書き込む
// 	memset(buf+2,'\0',-1);

// 	//表示
// 	printf("buf文字列→%s\n",buf);

// 	return (0);
// }