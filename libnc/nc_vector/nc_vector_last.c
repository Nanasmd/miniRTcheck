/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:32:38 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:32:38 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	*nc_vector_last(t_vector *vector)
{
	if (!vector || !vector->size)
		return (NULL);
	return (vector->array[vector->size - 1]);
}
