/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:12:13 by astachni          #+#    #+#             */
/*   Updated: 2023/01/09 18:09:51 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	close_mlx(t_perso_env *mlx)
{
	mlx_destroy_window(mlx->init, mlx->win);
	exit(0);
	return (0);
}
