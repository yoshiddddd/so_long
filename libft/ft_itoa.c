/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:45:53 by kyoshida          #+#    #+#             */
/*   Updated: 2023/05/31 14:48:41 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digitcount(int n)
{
	long	n2;
	int		digit;

	digit = 1;
	n2 = (long)n;
	if (n2 < 0)
	{
		n2 *= -1;
		digit++;
	}
	while (n2 >= 10)
	{
		n2 /= 10;
		digit++;
	}
	return (digit);
}

int	ft_flag(long n2)
{
	int	flag;

	flag = 0;
	if (n2 < 0)
		flag = 1;
	return (flag);
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*ans;
	long	n2;
	int		flag;

	n2 = (long)n;
	digit = ft_digitcount(n);
	flag = ft_flag(n2);
	if (flag == 1)
		n2 *= -1;
	ans = (char *)ft_calloc(sizeof(char), digit + 1);
	if (ans == NULL)
		return (NULL);
	while (digit > 0)
	{
		ans[digit - 1] = (n2 % 10) + '0';
		n2 /= 10;
		digit--;
	}
	if (flag == 1)
		ans[0] = '-';
	return (ans);
}

// int	main(void)
// {
// }