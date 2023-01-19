/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:07:11 by astachni          #+#    #+#             */
/*   Updated: 2023/01/19 17:43:48 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_perso_env_map	*position(t_perso_env_map *env, char c)
{
	if (c == 'P')
	{
		env->perso.position[0] = env->map.position[0];
		env->perso.position[1] = env->map.position[1];
	}
	else if (c == 'C')
	{
		env->item.nb_item += 1;
		env->item.position[0] = env->map.position[0];
		env->item.position[1] = env->map.position[1];
	}
	else if (c == 'E')
	{
		env->exit.position[0] = env->map.position[0];
		env->exit.position[1] = env->map.position[1];
	}
	return (env);
}

t_perso_env_map	*take_sprite(char c, t_perso_env_map *env)
{
	if (c == '1')
	{
		if (env->map.path)
			free(env->map.path);
		env->map.path = ft_strdup("./sprites/obstacle1.xpm");
	}
	else if (c == '0' || c == 'P' || c == 'E' || c == 'C')
	{
		if (env->map.path)
			free(env->map.path);
		env->map.path = ft_strdup("./sprites/grass0.xpm");
	}
	return (env);
}

int	import_sprite(size_t i, char *str, t_perso_env_map *env)
{
	take_sprite(str[i], env);
	import_map(env);
	if (str[i] == 'P')
	{
		env = position(env, str[i]);
		env->perso.img_ptr = import_sprite_charactere(env);
	}
	else if (str[i] == 'C')
	{
		env = position(env, str[i]);
		env->item.itm_ptr = import_item(env);
	}
	else if (str[i] == 'E')
	{
		env = position(env, str[i]);
		env->exit.img_ptr = import_exit(env);
	}
	return (i);
}

int	open_fd(int ac, char **av)
{
	int		fd;

	if (ac < 2)
		return (-1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

t_perso_env_map	read_map(t_perso_env_map *env)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = env->map.map_char[i];
	env->item.collected = 0;
	env->item.nb_item = 0;
	while (str && env->map.map_char[i])
	{
		ft_printf("%s", env->map.map_char[i]);
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
