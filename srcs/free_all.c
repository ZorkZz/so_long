/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:01:20 by astachni          #+#    #+#             */
/*   Updated: 2023/01/25 18:14:05 by astachni         ###   ########.fr       */
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

void	*free_all(int value, t_game *env)
{
	if (value == 0)
		return (free(env->perso.path), NULL);
	else if (value == 1)
	{
		free(env->perso.path);
		free(env->perso.img_ptr);
		return (NULL);
	}
	else if (value == 2)
	{
		free(env->map.path);
		return (NULL);
	}
	else if (value == 3)
	{
		free(env->map.path);
		free(env->map.img_ptr);
		return (NULL);
	}
	return (free(env->perso.path), \
		free(env->perso.img_ptr), \
		free(env->map.img_ptr), free(env->map.path), NULL);
}
