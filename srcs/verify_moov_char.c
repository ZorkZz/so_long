/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_moov_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:55:46 by astachni@st       #+#    #+#             */
/*   Updated: 2023/01/16 22:35:20 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_perso_env_map	*up_down(t_perso_env_map *env, int moov, size_t i, size_t j)
{
	char	c;

	env->perso.can_moov = -1;
	if (moov == 1)
	{
		c = env->map.map_char[i - 1][j];
		if (c == 'o')
		{
			env->map.map_char[i - 1][j] = 'p';
			env->map.map_char[i][j] = 'o';
			env->perso.can_moov = 1;
		}
	}
	else if (moov == 2)
	{
		c = env->map.map_char[i + 1][j];
		if (c == 'o')
		{
			env->map.map_char[i + 1][j] = 'p';
			env->map.map_char[i][j] = 'o';
			env->perso.can_moov = 1;
		}
	}
	return (env);
}

t_perso_env_map	*left_right(t_perso_env_map *env, int moov, size_t i, size_t j)
{
	char	c;

	env->perso.can_moov = -1;
	if (moov == 3)
	{
		c = env->map.map_char[i][j - 1];
		if (c == 'o')
		{
			env->map.map_char[i][j - 1] = 'p';
			env->map.map_char[i][j] = 'o';
			env->perso.can_moov = 1;
		}
	}
	else if (moov == 4)
	{
		c = env->map.map_char[i][j + 1];
		if (c == 'o')
		{
			env->map.map_char[i][j + 1] = 'p';
			env->map.map_char[i][j] = 'o';
			env->perso.can_moov = 1;
		}
	}
	return (env);
}

t_perso_env_map	*verify_moov_char(t_perso_env_map *env, int moov)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (env->map.map_char && env->map.map_char[i])
	{
		j = 0;
		while (env->map.map_char[i][j] && env->map.map_char[i][j] != 'p')
			j++;
		if (env->map.map_char[i][j] == 'p')
		{
			if (moov == 1 || moov == 2)
				return (up_down(env, moov, i, j));
			else if (moov == 3 || moov == 4)
				return (left_right(env, moov, i, j));
		}
		i++;
	}
	return (env);
}
