/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:33:34 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:33:35 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

int	nc_numlen(int n)
{
	int		size;
	long	num;

	size = 1;
	num = n;
	if (n < 0)
	{
		num = -num;
		size++;
	}
	while (num >= 10)
	{
		num /= 10;
		size++;
	}
	return (size);
}
