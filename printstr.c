/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gt-serst <gt-serst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:37:44 by gt-serst          #+#    #+#             */
/*   Updated: 2023/10/20 16:46:29 by gt-serst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printstr(char *s)
{
	int	print_length;
	int	tmp;

	if (!s)
		return (write(1, "(null)", 6));
	print_length = 0;
	tmp = 0;
	while (s[tmp] != '\0')
		print_length += printchar(s[tmp++]);
	return (print_length);
}
