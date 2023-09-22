/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:32:23 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:32:23 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

t_vector	*nc_vector_copy(t_vector *vector)
{
	t_vector	*copy;

	copy = nc_vector_new(vector->cpy, vector->cmp, vector->del, vector->print);
	if (!copy)
		return (NULL);
	copy->size = vector->size;
	nc_matrix_delete(copy->array, copy->del);
	copy->array = nc_matrix_copy(vector->array, copy->cpy);
	return (copy);
}
