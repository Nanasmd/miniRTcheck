/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:33:15 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:33:16 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

int	nc_clamp(int n, int min, int max)
{
	if (n > max)
		return (max);
	else if (n < min)
		return (min);
	return (n);
}
