/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pputnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshidakazushi <yoshidakazushi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:24:34 by kyoshida          #+#    #+#             */
/*   Updated: 2023/08/08 14:42:06 by yoshidakazu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pputnbr_fd(int n, t_flag *flag, int *count)
{
	long	i;

	i = (long)n;
	if (i < 0)
		i *= -1;
	if (i > 9)
	{
		ft_pputnbr_fd(i / 10, flag, count);
		ft_pputnbr_fd(i % 10, flag, count);
	}
	else
	{
		*count += ft_putchar(i + '0');
	}
}
