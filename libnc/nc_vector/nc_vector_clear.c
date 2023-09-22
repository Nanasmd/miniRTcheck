/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:32:19 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:32:19 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_vector_clear(t_vector *vector)
{
	uint32_t	size;

	if (!vector)
		return ;
	size = vector->size + 1;
	while (--size)
		nc_vector_pop(vector);
}
