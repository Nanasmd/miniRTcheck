/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:32:34 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:32:34 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	*nc_vector_first(t_vector *vector)
{
	if (!vector || !vector->size)
		return (NULL);
	return (vector->array[0]);
}
