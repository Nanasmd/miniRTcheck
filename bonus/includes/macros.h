/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <nasamadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:21:40 by nasamadi          #+#    #+#             */
/*   Updated: 2023/09/24 20:50:41 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <pthread.h>

//! Debug related macros

/*# define DEBUG
# define HERE 		printf("HERE\n");*/

//! Parsing macros

# define X 0
# define Y 1
# define Z 2

# define R 0
# define G 1
# define B 2

# define HAS_COMMAS '1'

//! Math macros 

# define PI 3.1415926535f
# define EPSILON 0.0001

//! Menu movement macros

# define MOVE 3
# define LEN 0.5
# define ROTATE 0.1

//! Illumination macros

# define KD 0.8

//! Threads rendering macro

# define NUM_THREADS 16

//! Error macros

# define ERROR_SYNTAX		"Syntax: file format misconfiguration."
# define ERROR_NOT_RT		"File extension is not '.rt'."
# define ERROR_OPEN_FILE	"Couldn't open requested file"
# define ERROR_EMPTY_MAP	"Empty map."
# define ERROR_NO_CAMERA	"No camera in the map."
# define ERROR_TOO_MANY		"Found more than 1 A or C entities"
# define ERROR_MALLOC		"Failed allocation"
# define ERROR_USAGE 		"Usage: ./miniRT <scene>.rt"

//! Fixed t_color structs

/*# define WHITE		(t_color){0, 255, 255, 255}
# define BLACK		(t_color){0, 0, 0, 0}
# define BLUE		(t_color){0, 0, 0, 255}
# define RED		(t_color){0, 255, 0, 0}
# define GREEN		(t_color){0, 0, 255, 0}
# define YELLOW		(t_color){0, 255, 255, 0}
# define PINK		(t_color){0, 255, 0, 255}
# define CYAN		(t_color){0, 0, 255, 255}*/

//! Fixed t_vec3 structs

/*# define UPGUIDE		(t_vec3){0.0, 1.0, 0.0}
# define VEC_MIN		(t_vec3){-1.0001, -1.0001, -1.0001}
# define VEC_MAX		(t_vec3){1.0001, 1.0001, 1.0001}
# define VEC_EPSILON	(t_vec3){EPSILON, EPSILON, EPSILON}*/

//! Viewport and window macros

# ifdef __APPLE__
#  define WIDTH 1440
# else
#  define WIDTH 1920
# endif

/*# define RATIO 	(16.0/9.0)
# define HEIGHT (WIDTH/RATIO)*/

//! Minilibx events

# ifdef __APPLE__
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define C 8
#  define V 9
#  define Q 12
#  define M 46
#  define O 31
#  define SPACE 49
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
#  define ONE 18
#  define TWO 19
#  define THREE 20
#  define FOUR 21
#  define FIVE 23
#  define SIX 22
#  define SEVEN 26
#  define EIGHT 28
#  define NINE 25
#  define KEYPRESS 2
#  define KEYPRESSMASK 1
#  define DESTROYNOTIFY 17
#  define STRUCTURENOTIFYMASK 131072
# else
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define C 99
#  define V 118
#  define Q 113
#  define M 109
#  define O 111
#  define SPACE 32
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define ONE 49
#  define TWO 50
#  define THREE 51
#  define FOUR 52
#  define FIVE 53
#  define SIX 54
#  define SEVEN 55
#  define EIGHT 56
#  define NINE 57
# endif

#endif