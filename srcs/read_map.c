/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:07:11 by astachni          #+#    #+#             */
/*   Updated: 2023/01/16 23:38:11 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	obstacle(size_t i, char *str, t_perso_env_map *env)
{
	if (str[i] == 'x')
	{
		if (env->map.path)
			free(env->map.path);
		env->map.path = ft_strdup("./sprites/obstacle1.xpm");
	}
}

void	grass(size_t i, char *str, t_perso_env_map *env)
{
	if (str[i] == 'o')
	{
		if (env->map.path)
			free(env->map.path);
		env->map.path = ft_strdup("./sprites/grass0.xpm");
	}
}

int	perso(size_t i, char *str, t_perso_env_map *env)
{
	if (str[i] == 'p')
	{
		env->perso.position[0] = env->map.position[0];
		env->perso.position[1] = env->map.position[1];
		env->perso.img_ptr = import_sprite_charactere(env);
		i++;
		env->map.position[0] += 64;
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
	while (str && env->map.map_char[i])
	{
		ft_printf("%s", env->map.map_char[i]);
		j = 0;
		while (str && str[j] && str[j] != '\n')
		{
			obstacle(j, str, env);
			grass(j, str, env);
			j = perso(j, str, env);
			import_map(env);
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
