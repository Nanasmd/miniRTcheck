/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:32:15 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:32:15 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	*nc_vector_at(t_vector *vector, uint32_t i)
{
	if (vector && i < vector->size)
		return (vector->array[i]);
	return (NULL);
}
