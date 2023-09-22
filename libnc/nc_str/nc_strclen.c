/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:30:55 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:30:56 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

size_t	nc_strclen(char *str, char *delim)
{
	size_t	i;

	i = 0;
	while (str[i] && !nc_strchr(delim, str[i]))
		i++;
	return (i);
}
