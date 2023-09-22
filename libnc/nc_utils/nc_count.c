/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:33:24 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:33:25 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

int	nc_count(char *str, char c)
{
	int	counter;

	counter = 0;
	while (*str)
		if (*str++ == c)
			counter++;
	return (counter);
}
