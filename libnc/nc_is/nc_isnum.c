/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:28:32 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:28:33 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

bool	nc_isnum(char *str, char *delims)
{
	if (*str == '-')
		++str;
	if (nc_strchr(delims, *str) || *str == '\0')
		return (false);
	while (*str && !nc_strchr(delims, *str))
		if (!nc_isdigit(*str++))
			return (false);
	return (true);
}
