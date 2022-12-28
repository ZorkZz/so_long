/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:46:03 by astachni          #+#    #+#             */
/*   Updated: 2022/12/28 23:41:10 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <mlx.h>
# include <stddef.h>
# include "../libs/ft_printf/ft_printf.h"

# ifndef WIN_LENGHT
#  define WIN_LENGHT 960
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH 540
# endif

typedef struct s_var
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_var;


int	open_win(t_var *mlx_ptr, t_var *win_ptr, char *title);


#endif