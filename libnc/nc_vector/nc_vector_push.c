/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:33:06 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:33:06 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_vector_push(t_vector *vector, void *element)
{
	void	**matrix;

	if (!vector)
		return ;
	matrix = nc_matrix_append(vector->array, element, vector->cpy);
	nc_matrix_delete(vector->array, vector->del);
	vector->array = matrix;
	vector->size++;
}
