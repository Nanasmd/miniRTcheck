/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_matrix_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:28:49 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:28:49 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	*nc_matrix_append(void *matrix, void *data, void *(*copy)(void *))
{
	void	**res;
	size_t	i;

	i = -1;
	res = nc_calloc(nc_matrix_size(matrix) + 2, sizeof(void *));
	while (((void **)matrix)[++i])
	{
		if (copy)
			res[i] = (*copy)(((void **)matrix)[i]);
		else
			res[i] = ((void **)matrix)[i];
	}
	res[i] = data;
	return (res);
}
