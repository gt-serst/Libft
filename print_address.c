/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:20:37 by gt-serst          #+#    #+#             */
/*   Updated: 2023/06/07 10:24:11 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!base[i])
		return (0);
	if (base[0] == 0 || base[1] == 0)
		return (0);
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static int	convert_base(unsigned long nbr, char *base, int len_base,
int print_length)
{
	if (nbr < (unsigned long)len_base)
		return (printchar(base[nbr]));
	print_length = convert_base(nbr / len_base, base, len_base,
			print_length);
	return (print_length + convert_base(nbr % len_base, base, len_base,
			print_length));
}

int	print_address(unsigned long nbr, char *base)
{
	int	len_base;
	int	print_length;

	len_base = ft_strlen(base);
	print_length = 0;
	print_length += printnbr_base(0, "0123456789");
	print_length += printchar('x');
	if (check_base(base))
	{
		if (nbr == 0)
			print_length += printchar(base[0]);
		else if (nbr < 0)
		{
			print_length += printchar('-');
			nbr = -nbr;
			print_length += convert_base(nbr, base, len_base, print_length);
		}
		else
			print_length += convert_base(nbr, base, len_base, print_length);
	}
	return (print_length);
}
