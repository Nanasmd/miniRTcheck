/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:32:56 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:32:56 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_vector_print(t_vector *vector)
{
	uint32_t	i;

	if (!vector)
		return ;
	i = -1;
	while (++i < vector->size)
		(*vector->print)(vector->array[i]);
}
