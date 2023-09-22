/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:30:07 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:30:08 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (s)
		nc_putstr_fd(s, fd);
	nc_putchar_fd('\n', fd);
}
