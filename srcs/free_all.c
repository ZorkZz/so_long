/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:01:20 by astachni          #+#    #+#             */
/*   Updated: 2023/01/13 20:57:50 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

/*
** free structure
**
** @param int value 0	perso-> position and path
** @param int value 1	perso-> img_ptr and 0
** @param int value 2	map like 0
** @param int value 3	map like 1
** @param int value all	all
**
*/

void	*free_all(int value, t_perso_env_map *env)
{
	if (value == 0)
	{
		free(env->perso.position);
		return (free(env->perso.path), NULL);
	}
	else if (value == 1)
	{
		free(env->perso.path);
		free(env->perso.img_ptr);
		return (free(env->perso.position), NULL);
	}
	else if (value == 2)
	{
		free(env->map.path);
		return (free(env->map.position), NULL);
	}
	else if (value == 3)
	{
		free(env->map.path);
		free(env->map.img_ptr);
		return (free(env->map.position), NULL);
	}
	return (free(env->perso.position), free(env->perso.path), \
		free(env->perso.img_ptr), free(env->map.position), \
		free(env->map.img_ptr), free(env->map.path), NULL);
}
