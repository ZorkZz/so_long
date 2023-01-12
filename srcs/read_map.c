/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:07:11 by astachni          #+#    #+#             */
/*   Updated: 2023/01/12 18:38:25 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	obstacle(int i, char *str, t_img *map)
{
	if (str[i] == 'x')
	{
		if (map->path)
			free(map->path);
		map->path = ft_strdup("./sprites/obstacle1.xpm");
	}
}

void	grass(int i, char *str, t_img *map)
{
	if (str[i] == 'o')
	{
		if (map->path)
			free(map->path);
		map->path = ft_strdup("./sprites/grass0.xpm");
	}
}

int	perso(int i, char *str, t_img *map, t_perso_env *mlx)
{
	if (str[i] == 'p')
	{
		mlx->position[0] = map->position[0];
		mlx->position[1] = map->position[1];
		mlx->img_ptr = import_sprite_charactere(mlx);
		i++;
		map->position[0] += 64;
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


t_img	read_map(int ac, char **av, t_img *map, t_perso_env *mlx)
{
	int		fd;
	char	*str;
	int		i;

	fd = open_fd(ac, av);
	if (fd == -1)
	{
		map->img_ptr = NULL;
		return (*map);
	}
	str = get_next_line(fd);
	while (str)
	{
		i = 0;
		while (str && str[i] && str[i] != '\n')
		{
			obstacle(i, str, map);
			grass(i, str, map);
			i = perso(i, str, map, mlx);
			import_map(mlx, map);
			map->position[0] += 64;
			i++;
		}
		map->position[1] += 64;
		map->position[0] = 0;
		free(str);
		str = get_next_line(fd);
	}
	if (str)
		free(str);
	return (*map);
}
