/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:27:51 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:27:51 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

static int	get_size(int n)
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

char	*nc_itoa(int n)
{
	long	num;
	int		size;
	char	*str;

	num = n;
	if (n < 0)
		num = -num;
	size = get_size(n);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	str[size--] = '\0';
	while (num > 0)
	{
		str[size--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
