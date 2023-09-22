/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:27:47 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:27:48 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

static int	nc_isspace(char c)
{
	return (c == '\f' || c == '\n'
		|| c == '\r' || c == '\t'
		|| c == '\v' || c == ' ');
}

int	nc_atoi(const char *nptr)
{
	int		i;
	int		res;
	int		signal;

	i = 0;
	res = 0;
	signal = 1;
	while (nc_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signal = -1;
		i++;
	}
	while (nc_isdigit(nptr[i]))
		res = res * 10 + nptr[i++] - '0';
	return (signal * res);
}
