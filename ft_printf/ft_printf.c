/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshida <kyoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:48:23 by kyoshida          #+#    #+#             */
/*   Updated: 2023/06/22 18:15:17 by kyoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ans;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	ans = ft_judgment(args, format);
	va_end(args);
	return (ans);
}

// int main(void)
// {
// 	int ft;
// 	int lib;
// 	// int asterisk = 15;
// 	// int as2 = 0;
// 	// int num = 1000;t
// 	// char *str = NULL;
// 	// char c = 1270;

// 	ft_printf("[");
// ft = ft_printf("%8.0u",0);
// 	ft_printf("]\n[");
// 	lib = printf("%8.0u",0);
// 	printf("]\n");
// 	printf("ft :%d\n", ft);
// 	printf("lib:%d\n", lib);
// }