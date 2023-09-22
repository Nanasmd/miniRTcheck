/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_replace_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:30:38 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:30:38 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

char	*nc_replace_all(char *str, char *old, char *new)
{
	char	*res;
	char	*tmp;

	res = nc_strdup(str);
	while (nc_strnstr(res, old, nc_strlen(res)))
	{
		tmp = res;
		res = nc_replace(res, old, new);
		free(tmp);
	}
	return (res);
}
