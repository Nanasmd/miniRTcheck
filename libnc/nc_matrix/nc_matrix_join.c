/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_matrix_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:29:01 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:29:02 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	*nc_matrix_join(void *matrix, void *data, void *(*copy)(void *), \
	void (*del)(void *))
{
	void	*appended;

	appended = nc_matrix_append(matrix, data, copy);
	nc_matrix_delete(matrix, del);
	return (appended);
}
