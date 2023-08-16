/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:35:23 by kyoshida          #+#    #+#             */
/*   Updated: 2023/05/30 19:55:40 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int num)
{
	return (ft_isalpha(num) || ft_isdigit(num));
}

// int	main(void)
// {
// 	if(ft_isalnum('d')==0)
// 	puts("no");
// 	else
// 	puts("yes");
// }