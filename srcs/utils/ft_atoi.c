/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:42:05 by panger            #+#    #+#             */
/*   Updated: 2023/12/06 11:14:45 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	tot;
	int	sign;

	i = 0;
	tot = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		tot = tot * 10 + (nptr[i] - 48);
		i++;
	}
	return (tot * sign);
}

static int	check_base(char c)
{
	int			i;
	char		*base;

	i = 0;
	base = "0123456798abcdef";
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i ++;
	}
	return (-1);
}

__uint64_t	ft_atoi_colors(const char *nptr)
{
	int			i;
	__uint64_t	tot;
	char		*base;

	i = 0;
	base = "0123456798abcdef";
	tot = 0;
	if (nptr[i]  == '0' && nptr[i + 1] == 'x')
		i += 2;
	while (check_base(nptr[i]) != -1)
	{
		tot = tot * 16 + check_base(nptr[i]);
		i ++;
	}
	return (tot);
}