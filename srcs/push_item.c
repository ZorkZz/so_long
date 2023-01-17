/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:35:49 by astachni@st       #+#    #+#             */
/*   Updated: 2023/01/17 20:19:51 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_perso_env_map	push_item(t_perso_env_map *env)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (env->map.map_char[i])
	{
		j = 0;
		while (env->map.map_char[i][j])
		{
			if (env->map.map_char[i][j] == 'C')
			{
				env->item.position[i] = i * 64;
				env->item.position[j] = j * 64;
				env->item.itm_ptr = import_item(env);
			}
			j++;
		}
		i++;
	}
	return (*env);
}
