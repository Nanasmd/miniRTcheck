/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:32:46 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:32:46 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

t_vector	*nc_vector_new(void *(*cpy)(), int (*cmp)(void *, void *), \
	void (*del)(void *), void (*print)(void *))
{
	t_vector	*vector;

	vector = nc_calloc(1, sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->array = nc_calloc(1, sizeof(void *));
	if (!vector->array)
	{
		free(vector);
		return (NULL);
	}
	vector->cpy = cpy;
	vector->cmp = cmp;
	vector->del = del;
	vector->print = print;
	return (vector);
}
