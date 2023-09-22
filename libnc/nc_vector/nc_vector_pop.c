/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:32:51 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:32:51 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_vector_pop(t_vector *vector)
{
	if (!vector || !vector->size)
		return ;
	if (vector->del)
		(*vector->del)(vector->array[vector->size - 1]);
	vector->array[vector->size - 1] = NULL;
	--vector->size;
}
