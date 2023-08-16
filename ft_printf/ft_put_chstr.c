/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:09:51 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/08 15:31:50 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char s)
{
	write(1, &s, 1);
	return (1);
}

int	ft_putstr(char *s, int writelen)
{
	int	i;

	i = 0;
	if (writelen == -1)
		writelen = (int)ft_pstrlen(s);
	if (writelen < 0)
		writelen = writelen * -1;
	while (s[i] != '\0' && writelen > 0)
	{
		write(1, &s[i], 1);
		i++;
		writelen--;
	}
	return (i);
}
