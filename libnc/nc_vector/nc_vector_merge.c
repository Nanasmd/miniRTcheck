/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:32:43 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:32:43 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

t_vector	*nc_vector_merge(t_vector *v1, t_vector *v2)
{
	t_vector	*vector;

	if (v1->cpy != v2->cpy || v1->cmp != v2->cmp || v1->del != v2->del)
		return (NULL);
	vector = nc_vector_new(v1->cpy, v1->cmp, v1->del, v1->print);
	if (!vector)
		return (NULL);
	nc_matrix_delete(vector->array, vector->del);
	vector->array = nc_matrix_merge(v1->array, v2->array, vector->cpy);
	vector->size = v1->size + v2->size;
	return (vector);
}
