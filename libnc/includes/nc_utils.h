/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:20:46 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/25 13:25:51 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NC_UTILS_H
# define NC_UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <ctype.h>

/**
 * @brief Checks how many digits the number will have
 * 
 * @param n The number to check
 * @return int The size of the number
 */
int			nc_numlen(int n);

/**
 * @brief Given a string, it counts the occurences of the char c
 * int the string str
 * 
 * @param str The string to look on
 * @param c The character to search for
 * @return int The number of occurences 
 */
int			nc_count(char *str, char c);

/**
 * @brief Frees the memory associated with ptr, only if ptr exists
 * 
 * @param ptr Pointer to be freed
 */
void		nc_free(void *ptr);

/**
 * @brief Given an integer n, this function makes sure that n
 * is between min and max. If n is greater than max, it returns
 * max. If n is less than min, it returns min. Otherwise, it
 * returns n.
 * 
 * @param n  The number to clamp
 * @param min The lowest value
 * @param max The biggest value
 * @return The clamped number
 */
int			nc_clamp(int n, int min, int max);
// Returns the maximum between a and b
double		max(double a, double b);
// Returns the minimum between a and b
double		min(double a, double b);
// Returns the absolute value of x
int			abs_val(int x);
// Returns 1 if x is odd, 0 otherwise
int			odd(int x);
// Returns 1 if x is even, 0 otherwise
int			even(int x);
// Return the value of the nth bit of x
int			bit(int n);

#endif