/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_defines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:04:06 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/25 13:26:10 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

double	max(double a, double b)
{
	return ((a * (a > b) + (b * (b > a))));
}

double	min(double a, double b)
{
	return ((a * (a < b) + (b * (b < a))));
}

int	abs_val(int x)
{
	return ((x * (x > 0) - x * (x < 0)));
}

int	odd(int x)
{
	return (x & 1);
}

int	even(int x)
{
	return (!odd(x));
}
