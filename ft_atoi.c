/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:14:34 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/24 11:55:40 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			tmp;
	int			sign;
	long long	number;

	tmp = 0;
	sign = 1;
	number = 0;
	while (str[tmp] == 32 || (str[tmp] >= 9 && str[tmp] <= 13))
		tmp++;
	if (str[tmp] == '-')
	{
		sign = -sign;
		tmp++;
	}
	else if (str[tmp] == '+')
		tmp++;
	while (str[tmp] >= '0' && str[tmp] <= '9')
	{
		number = number * 10 + str[tmp] - '0';
		tmp++;
	}
	if (number >= LONG_MAX && sign % 2 == 0)
		return (0);
	if (number >= LONG_MAX && sign % 2 == 1)
		return (-1);
	return (number * sign);
}

/*
#include <stdio.h>
int	main()
{
	char	str[] = "-9223372036854775808";

	printf("%d\n", ft_atoi(str));
	printf("%d", atoi(str));
	return (0);
}
*/
