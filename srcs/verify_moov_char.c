/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_moov_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:55:46 by astachni@st       #+#    #+#             */
/*   Updated: 2023/01/19 17:50:22 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_perso_env_map	*up_down(t_perso_env_map *env, int moov, size_t i, size_t j)
{
	char	c;

	env->perso.can_moov = -1;
	c = 0;
	if (moov == 1)
	{
		c = env->map.map_char[i - 1][j];
		if (c == '0' || c == 'C')
		{
			env->map.map_char[i - 1][j] = 'P';
			env->map.map_char[i][j] = '0';
			env->perso.can_moov = 1;
		}
	}
	else if (moov == 2)
	{
		c = env->map.map_char[i + 1][j];
		if (c == '0' || c == 'C')
		{
			env->map.map_char[i + 1][j] = 'P';
			env->map.map_char[i][j] = '0';
			env->perso.can_moov = 1;
		}
	}
	if (c == 'C')
		env->item.collected += 1;
	if (env->item.collected == env->item.nb_item && c == 'C')
		ft_printf("\nyou can exit\n");
	if (env->item.collected == env->item.nb_item && c == 'E')
	{
		ft_printf("\nYOU WIN\n");
		exit(0);
	}
	return (env);
}

t_perso_env_map	*left_right(t_perso_env_map *env, int moov, size_t i, size_t j)
{
	char	c;

	c = 0;
	env->perso.can_moov = -1;
	if (moov == 3)
	{
		c = env->map.map_char[i][j - 1];
		if (c == '0' || c == 'C')
		{
			env->map.map_char[i][j - 1] = 'P';
			env->map.map_char[i][j] = '0';
			env->perso.can_moov = 1;
		}
	}
	else if (moov == 4)
	{
		c = env->map.map_char[i][j + 1];
		if (c == '0' || c == 'C')
		{
			env->map.map_char[i][j + 1] = 'P';
			env->map.map_char[i][j] = '0';
			env->perso.can_moov = 1;
		}
	}
	if (c == 'C')
		env->item.collected += 1;
	if (env->item.collected == env->item.nb_item && c == 'C')
		ft_printf("\nyou can exit\n");
	if (env->item.collected == env->item.nb_item && c == 'E')
	{
		ft_printf("\nYOU WIN\n");
		exit(0);
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
		while (env->map.map_char[i][j] && env->map.map_char[i][j] != 'P')
			j++;
		if (env->map.map_char[i][j] == 'P')
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
