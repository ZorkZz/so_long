/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_moov_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:55:46 by astachni@st       #+#    #+#             */
/*   Updated: 2023/03/27 14:47:24 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_game	*can_exit(t_game *env, char c)
{
	if (c == 'N')
	{
		ft_printf("\nYou lost\n");
		close_mlx(env);
	}
	if (c == 'C' || c == '0')
		env->perso.can_moov = 1;
	if (c == 'C')
		env->item.collected += 1;
	if (env->item.collected == env->item.nb_item && c == 'C')
		ft_printf("\nyou can exit\n");
	if (env->item.collected == env->item.nb_item && c == 'E')
	{
		ft_printf("\nYOU WIN\n");
		close_mlx(env);
	}
	return (env);
}

t_game	*up_down(t_game *env, int moov, size_t i, size_t j)
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
		}
	}
	else if (moov == 2)
	{
		c = env->map.map_char[i + 1][j];
		if (c == '0' || c == 'C')
		{
			env->map.map_char[i + 1][j] = 'P';
			env->map.map_char[i][j] = '0';
		}
	}
	env = can_exit(env, c);
	return (env);
}

t_game	*left_right(t_game *env, int moov, size_t i, size_t j)
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
		}
	}
	else if (moov == 4)
	{
		c = env->map.map_char[i][j + 1];
		if (c == '0' || c == 'C')
		{
			env->map.map_char[i][j + 1] = 'P';
			env->map.map_char[i][j] = '0';
		}
	}
	env = can_exit(env, c);
	return (env);
}

t_game	*verify_moov_char(t_game *env, int moov)
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
