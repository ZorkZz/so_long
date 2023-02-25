/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:07:11 by astachni          #+#    #+#             */
/*   Updated: 2023/02/25 17:28:06 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_game	*position(t_game *env, char c)
{
	if (c == 'P')
	{
		env->perso.position[0] = env->map.position[0];
		env->perso.position[1] = env->map.position[1];
	}
	else if (c == 'C')
	{
		env->item.position[0] = env->map.position[0];
		env->item.position[1] = env->map.position[1];
	}
	else if (c == 'E')
	{
		env->exit.position[0] = env->map.position[0];
		env->exit.position[1] = env->map.position[1];
	}
	else if (c == 'N')
	{
		env->enemy.position[0] = env->map.position[0];
		env->enemy.position[1] = env->map.position[1];
	}
	return (env);
}

t_game	*take_sprite(char c, t_game *env)
{
	if (c == '0' || c == 'P' || c == 'E' || c == 'C' || c == 'N')
		if (!env->map.path)
			env->map.path = ft_strdup("./sprites/grass0.xpm");
	return (env);
}

int	import_sprite(size_t i, char *str, t_game *env)
{
	if (str[i] == '0' || str[i] == '1')
	{
		if (str[i] == '0')
			import_map(env, 0);
		else if (str[i] == '1')
			import_map(env, 1);
		return (i);
	}
	env = position(env, str[i]);
	if (str[i] == 'P')
		import_sprite_charactere(env);
	else if (str[i] == 'C')
		import_item(env);
	else if (str[i] == 'E')
		import_exit(env);
	else if (str[i] == 'N')
		import_enemy(env);
	return (i);
}

int	open_fd(int ac, char **av)
{
	int		fd;

	if (ac != 2)
		return (-1);
	fd = open(av[1], O_RDONLY);
	if (ft_strncmp(&av[1][ft_strlen(av[1])] - 5, ".ber", 4) != 0)
		return (-1);
	if (fd < 0)
		return (-1);
	return (fd);
}

t_game	read_map(t_game *env)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = env->map.map_char[i];
	env->item.collected = 0;
	while (str && env->map.map_char[i])
	{
		j = 0;
		while (str && str[j] && str[j] != '\n')
		{
			j = import_sprite(j, str, env);
			env->map.position[0] += 64;
			j++;
		}
		env->map.position[1] += 64;
		env->map.position[0] = 0;
		i++;
		str = env->map.map_char[i];
	}
	return (*env);
}
