/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:01:20 by astachni          #+#    #+#             */
/*   Updated: 2022/12/31 15:26:29 by astachni         ###   ########.fr       */
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

void	*free_all(int value, t_perso *perso, t_img *map)
{
	if (value == 0)
	{
		free(perso->position);
		return (free(perso->path), NULL);
	}
	else if (value == 1)
	{
		free(perso->path);
		free(perso->img_ptr);
		return (free(perso->position), NULL);
	}
	else if (value == 2)
	{
		free(map->path);
		return (free(map->position), NULL);
	}
	else if (value == 3)
	{
		free(map->path);
		free(map->img_ptr);
		return (free(map->position), NULL);
	}
	return (free(perso->position), free(perso->path), free(perso->img_ptr),
		free(map->position), free(map->img_ptr), free(map->path), NULL);
}
