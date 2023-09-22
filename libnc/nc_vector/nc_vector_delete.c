/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:32:27 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:32:27 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_vector_delete(t_vector *vector)
{
	if (!vector)
		return ;
	nc_vector_clear(vector);
	nc_matrix_delete(vector->array, vector->del);
	free(vector);
}
