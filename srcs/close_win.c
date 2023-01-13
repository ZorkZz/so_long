/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:12:13 by astachni          #+#    #+#             */
/*   Updated: 2023/01/13 20:51:07 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	close_mlx(t_perso_env_map *env)
{
	mlx_destroy_window(env->mlx.init, env->mlx.win);
	exit(0);
	return (0);
}
