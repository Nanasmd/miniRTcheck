/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:27:43 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:27:44 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

static long	power(int n, int power)
{
	long	res;

	res = n;
	while (power > 1)
	{
		res = res * n;
		power--;
	}
	return (res);
}

double	nc_atod(char *str)
{
	int			i;
	double		res;
	double		signal;

	i = 0;
	res = 0.0;
	signal = 1.0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (nc_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	str += i;
	res += (double)nc_atoi(str) / power(10, nc_strlen(str));
	return (signal * res);
}
