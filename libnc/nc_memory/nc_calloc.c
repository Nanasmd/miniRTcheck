/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:29:35 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:29:36 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	*nc_calloc(size_t nmemb, size_t size)
{
	void	*buf;
	size_t	total;

	total = nmemb * size;
	buf = malloc(total);
	if (!buf)
		return (NULL);
	nc_bzero(buf, total);
	return (buf);
}
