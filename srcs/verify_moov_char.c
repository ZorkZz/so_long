/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_moov_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:55:46 by astachni@st       #+#    #+#             */
/*   Updated: 2023/01/15 23:36:16 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_perso_env_map	*verify_moov_char(t_perso_env_map *env, char *moov)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	if (ft_strncmp(moov, "up", 2))
	{
		while (env->map.map_char && env->map.map_char[i])
		{
			j = 0;
			while (*env->map.map_char && env->map.map_char[i][j] != 'p')
				j++;
			if (env->map.map_char[i][j] == 'p')
				break ;
			i++;
		}
		if (env->map.map_char[i - 1][j] == 'x')
			env->perso.can_moov = -1;
		else if (env->map.map_char[i - 1][j] == 'o')
		{
			c = env->map.map_char[i - 1][j];
			env->map.map_char[i - 1][j] = 'p';
			env->map.map_char[i][j] = 'o';
			env->perso.can_moov = 1;
		}
	}
	ft_printf("\n");
	while (env->map.map_char[i])
		ft_printf("%s", env->map.map_char[i++]);
	return (env);
}
