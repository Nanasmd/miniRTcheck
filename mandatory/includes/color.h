/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:13:59 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/21 11:14:01 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "miniRT.h"

/**
 * @brief Returns a new color with the given component values.
 * All components are clamped between 0 and 255.
 * 
 * @param r The red component  
 * @param g The green component
 * @param b The blue component
 * @return t_color The new color
 */
t_color	color_new(int r, int g, int b);

/**
 * @brief Given an existent color, it multiplies each component
 * by the parameter k, and returns the result. The final components
 * are clamped between 0 and 255.
 * 
 * @param color The color to change
 * @param k The parameter to multiply with
 * @return t_color The new color
 */
t_color	color_mult(t_color color, double k);

/**
 * @brief Adds two colors by addding each components.
 * The final components are clamped between 0 and 255.
 * 
 * @param c1 The first color
 * @param c2 The second color
 * @return t_color The final color
 */
t_color	color_add(t_color c1, t_color c2);

/**
 * @brief Given an array of strings, where each string maps to a
 * component (rgb[0] is red, rgb[1] is green and rgb[2] is blue),
 * converts the strings into a new color struct. All components
 * values are clamped between 0 and 255.
 * 
 * @param rgb The string array containing the component's values
 * @return t_color The new color
 */
t_color	color_from_strings(char **rgb);

#endif