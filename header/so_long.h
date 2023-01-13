/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:46:03 by astachni          #+#    #+#             */
/*   Updated: 2023/01/13 18:16:49 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# ifdef __APPLE__
#  include "../mlx/mlx.h"
# elif __linux__
#  include "../mlx_linux/mlx.h"
# endif
# include <stddef.h>
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
# include "struct.h"
# include "var.h"
# include "proto.h"
# include <fcntl.h>

#endif