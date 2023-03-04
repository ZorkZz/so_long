/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffusion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:37:27 by astachni          #+#    #+#             */
/*   Updated: 2023/03/04 18:01:43 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	diffusion(char **map, ssize_t x, ssize_t y)
{
	if (map[x + 1][y] == '0' || map[x + 1][y] == 'C' || map[x + 1][y] == 'E')
	{
		map[x + 1][y] = '*';
		diffusion(map, x + 1, y);
	}
	if (map[x - 1][y] == '0' || map[x - 1][y] == 'C' || map[x - 1][y] == 'E')
	{
		map[x - 1][y] = '*';
		diffusion(map, x - 1, y);
	}
	if (map[x][y + 1] == '0' || map[x][y + 1] == 'C' || map[x][y + 1] == 'E')
	{
		map[x][y + 1] = '*';
		diffusion(map, x, y + 1);
	}
	if (map[x][y - 1] == '0' || map[x][y - 1] == 'C' || map[x][y - 1] == 'E')
	{
		map[x][y - 1] = '*';
		diffusion(map, x, y - 1);
	}
}

ssize_t	*find_coor(char **map, t_game *env)
{
	ssize_t	*tab;

	tab = malloc(sizeof(ssize_t) * 2);
	if (!tab)
		error_map ("MALLOC ERROR", env);
	tab[0] = 0;
	tab[1] = 0;
	while (map && map[tab[0]])
	{
		tab[1] = 0;
		while (map[tab[0]][tab[1]])
		{
			if (map[tab[0]][tab[1]] == 'P')
				return (tab);
			tab[1] += 1;
		}
		tab[0] += 1;
	}
	return (tab);
}

void	map_is_ok(char **map, t_game *env, ssize_t *coor)
{
	ssize_t	x;
	ssize_t	y;

	x = 0;
	while (map && map[x])
	{
		y = 0;
		while (map[x] && map[x][y])
		{
			if (map[x][y] == 'C' || map[x][y] == 'E')
			{
				free_map(map);
				free(coor);
				error_map("BAD MAP\n", env);
			}
			y++;
		}
		x++;
	}
}

void	is_finish(t_game *env)
{
	char	**map;
	ssize_t	*coor;

	map = NULL;
	map = ft_strsdup(map, env->map.map_char);
	if (!map)
		error_map("BAD MAP", env);
	coor = find_coor(map, env);
	diffusion (map, coor[0], coor[1]);
	map_is_ok(map, env, coor);
	free(coor);
	free_map(map);
}
