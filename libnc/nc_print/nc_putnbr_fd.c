/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:30:14 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:30:15 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_putnbr_fd(int n, int fd)
{
	long int	num;

	num = n;
	if (fd < 0)
		return ;
	if (num < 0)
	{
		nc_putchar_fd('-', fd);
		num = -num;
	}
	if (num < 10)
		nc_putchar_fd(nc_tochar(num), fd);
	else
	{
		nc_putnbr_fd(num / 10, fd);
		nc_putchar_fd(nc_tochar(num % 10), fd);
	}
}
