/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:32:30 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:32:30 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	*nc_vector_find(t_vector *vector, void *element)
{
	uint32_t	i;

	i = -1;
	while (++i < vector->size)
		if (!(*vector->cmp)(vector->array[i], element))
			return (element);
	return (NULL);
}
