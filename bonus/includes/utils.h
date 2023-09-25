/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:22:12 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/24 21:43:00 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "miniRT.h"

/**
 * @brief funtion that prints the given error message as parameter and exits
 * the program destroying the world struct (freeing all the memory 
 * previously allocated)
 * 
 * @param world t_world struct with all the information of the world 
 * @param text text to be printed
 */
void		message(t_world *world, char *text);

/**
 * @brief A wrapper function to mlx_string_put from the mlx library
 * 
 * @param world t_world struct with all the information of the world 
 * @param xy x and y coordinates of the text
 * @param color color of the text
 * @param text text to be printed
 * @param line line where the error happened
 */
void		display(t_world *w, t_xy xy, int color, char *text);

/**
 * @brief function for optimization purposes, it calculates the constants
 * that are used for computing the shapes intersections for the whole program
 * avoiding extra calculations
 * 
 * @param shapes t_vector struct with all the shapes
 */
void		compute_shapes_constants(t_vector *shapes);

/**
 * @brief this function checks how many intersections the ray has with the
 * object.
 * 
 * @param eq t_equation struct with the equation information
 * @return number of intersections, -1 if there are no intersections
 */
double		determinant(t_equation *eq);

/**
 * @brief this function will solve the quadratic equation, store the results
 * inside the t_equation struct (t1 and t2 variables) and return the number 
 * of intersections the ray has with the object.
 * 
 * @param eq t_equation struct with the equation information
 * @return number of intersections, -1 if there are no intersections
 */
double		solve(t_equation *eq);

float		radians(float degrees);
float		degrees(float radians);

t_color		white(void);
t_color		black(void);
t_color		red(void);
t_color		green(void);
t_color		yellow(void);
t_color		pink(void);
t_color		cyan(void);
void		error(const char *m);
void		error_num_args(const char *x, const char *n);
void		error_num_commas(const char *x);
void		error_misformat_colors(const char *x);
void		error_ambient_ratio_out_of_bounds(const char *x);
void		error_camera_fov_out_of_bounds(void);
void		error_light_brightness_out_of_bounds(void);
void		error_normal_out_of_bounds(const char *x);
void		error_ks_out_of_bounds(const char *x);
void		error_shiniess_out_of_bounds(const char *x);
void		error_values_too_small(const char *x);
float		ratio(void);
int			height(void);

#endif