/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso_map_characteristics.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:52:20 by astachni          #+#    #+#             */
/*   Updated: 2023/01/02 23:21:08 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/so_long.h"

t_perso_env	perso_charact(t_perso_env *perso)
{
	perso->path = ft_strdup("./sprites/pikachu.xpm");
	perso->position = malloc(2 * sizeof(int));
	perso->position[0] = 64;
	perso->position[1] = 64;
	perso->img_ptr = NULL;
	return (*perso);
}

t_img	map_charact(t_img *map)
{
	map->path = ft_strdup("./sprites/obstacle0.xpm");
	map->position = malloc(2 * sizeof(int));
	map->position[0] = 0;
	map->position[1] = 0;
	return (*map);
}
