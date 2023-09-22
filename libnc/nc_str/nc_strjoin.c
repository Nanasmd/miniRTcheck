/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:31:11 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:31:12 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

char	*nc_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	len = nc_strlen(s1) + nc_strlen(s2);
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	nc_strlcat(res, s1, len + 1);
	nc_strlcat(res, s2, len + 1);
	return (res);
}
