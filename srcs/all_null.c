/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:52:07 by astachni          #+#    #+#             */
/*   Updated: 2023/03/04 17:07:30 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_game	all_null(t_game env)
{
	env.mlx.init_sprite = 0;
	env.enemy.img_ptr = NULL;
	env.enemy.path = NULL;
	env.exit.img_ptr = NULL;
	env.exit.path = NULL;
	env.item.itm_ptr = NULL;
	env.item.path = NULL;
	env.map.img_ptr01 = NULL;
	env.map.img_ptr = NULL;
	env.map.path01 = NULL;
	env.map.path = NULL;
	env.map.map_char = NULL;
	env.perso.path = NULL;
	env.perso.img_ptr = NULL;
	env.mlx.init = NULL;
	env.mlx.win = NULL;
	return (env);
}
