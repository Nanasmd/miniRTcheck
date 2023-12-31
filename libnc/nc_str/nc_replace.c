/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:30:42 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:30:42 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

char	*nc_replace(char *str, char *old, char *new)
{
	char	*ret;
	char	*tmp;
	char	*ptr;
	int		len;

	if (!str || !old || !new || !nc_strnstr(str, old, nc_strlen(str)))
		return (NULL);
	len = nc_strlen(str) + nc_strlen(new) - nc_strlen(old);
	ret = nc_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ptr = nc_strnstr(str, old, nc_strlen(str));
	tmp = nc_substr(str, 0, ptr - str);
	nc_strlcat(ret, tmp, len + 1);
	nc_strlcat(ret, new, len + 1);
	nc_strlcat(ret, ptr + nc_strlen(old), len + 1);
	free(tmp);
	return (ret);
}
