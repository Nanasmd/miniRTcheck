/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_matrix_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:28:57 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:28:57 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_matrix_delete(void *matrix, void (*del)(void *))
{
	size_t	i;

	if (!matrix)
		return ;
	if (del)
	{
		i = -1;
		while (((void **)matrix)[++i])
			del(((void **)matrix)[i]);
	}
	free(matrix);
}
