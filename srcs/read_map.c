/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:07:11 by astachni          #+#    #+#             */
/*   Updated: 2023/01/16 22:02:51 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	obstacle(int i, char *str, t_perso_env_map *env)
{
	if (str[i] == 'x')
	{
		if (env->map.path)
			free(env->map.path);
		env->map.path = ft_strdup("./sprites/obstacle1.xpm");
	}
}

void	grass(int i, char *str, t_perso_env_map *env)
{
	if (str[i] == 'o')
	{
		if (env->map.path)
			free(env->map.path);
		env->map.path = ft_strdup("./sprites/grass0.xpm");
	}
}

int	perso(int i, char *str, t_perso_env_map *env)
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

t_perso_env_map	map_read(int ac, char **av, t_perso_env_map *env)
{
	int		fd;
	char	*str;
	int		i;

	fd = open_fd(ac, av);
	if (fd < 0)
		return (*env);
	str = get_next_line(fd);
	i = 0;
	env->map.map_char = NULL;
	while (str)
	{
		env->map.map_char = parse_map(env, str);
		if (str)
			free(str);
		str = get_next_line(fd);
		i++;
	}
	if (str)
		free(str);
	return (*env);
}

t_perso_env_map	read_map(int ac, char **av, t_perso_env_map *env)
{
	int		fd;
	char	*str;
	int		i;

	fd = open_fd(ac, av);
	if (fd == -1)
	{
		env->map.img_ptr = NULL;
		return (*env);
	}
	str = get_next_line(fd);
	while (str)
	{
		i = 0;
		while (str && str[i] && str[i] != '\n')
		{
			obstacle(i, str, env);
			grass(i, str, env);
			i = perso(i, str, env);
			import_map(env);
			env->map.position[0] += 64;
			i++;
		}
		env->map.position[1] += 64;
		env->map.position[0] = 0;
		free(str);
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	return (*env);
}
