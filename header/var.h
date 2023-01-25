/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:23:11 by astachni          #+#    #+#             */
/*   Updated: 2023/01/25 18:05:49 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_H
# define VAR_H

# ifndef IMG_PATH
#  define IMG_PATH "../imgs/"
# endif

# ifdef __APPLE__

#  ifndef A
#   define A 0
#  endif

#  ifndef W
#   define W 13
#  endif

#  ifndef S
#   define S 1
#  endif

#  ifndef D
#   define D 2
#  endif

#  ifndef ESC
#   define ESC 53
#  endif

# elif __linux__

#  ifndef A
#   define A 'a'
#  endif

#  ifndef W
#   define W 'w'
#  endif

#  ifndef S
#   define S 's'
#  endif

#  ifndef D
#   define D 'd'
#  endif

#  ifndef ESC
#   define ESC 65307
#  endif

# endif

#endif