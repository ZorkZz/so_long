/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:17:21 by astachni@st       #+#    #+#             */
/*   Updated: 2023/01/22 20:32:43 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

char	**cpy_map(const char **map)
{
	size_t	i;
	char	**map_modif;

	map_modif = malloc((ft_strslen((char **)map)) + 1 * sizeof(char *));
	if (!map_modif)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_modif[i] = ft_strdup(map[i]);
		i++;
	}
	map_modif[i] = NULL;
	return (map_modif);
}

t_point	*possible_dest(char **map, t_point pos)
{
	t_point	*res;
	t_point	*ptr;

	res = malloc(sizeof(t_point) * 5);
	ptr = res;
	if (pos.x > 0 && map[pos.x - 1][pos.y] != 1)
		*ptr++ = (t_point){pos.x - 1, pos.y};
	if (pos.y > 0 && map[pos.x][pos.y - 1] != 1)
		*ptr++ = (t_point){pos.x, pos.y - 1};
	if (pos.x < 4 && map[pos.x + 1][pos.y] != 1)
		*ptr++ = (t_point){pos.x + 1, pos.y};
	if (pos.y < 4 && map[pos.x][pos.y + 1] != 1)
		*ptr++ = (t_point){pos.x, pos.y + 1};
	*ptr = (t_point){-1, -1};
	return (res);
}

void	finishable(char **map, t_point pos, ssize_t *count)
{
	t_point	*next_points;
	t_point	*next;

	ft_printf("\n%c\n", map[pos.x][pos.y]);
	if (map[pos.x][pos.y] == 1)
		return ;
	if (map[pos.x][pos.y] != 0)
		(*count)--;
	map[pos.x][pos.y] = 1;
	next_points = possible_dest(map, pos);
	next = next_points;
	while (next->x != -1 && next->y != -1)
	{
		finishable(map, *next, count);
		next++;
	}
}

int	map_verify(t_perso_env_map *env)
{
	ssize_t	count;
	char	**map_modif;

	map_modif = cpy_map((const char **)env->map.map_char);
	if (!map_modif)
		return (-1);
	count = env->item.nb_item;
	finishable(map_modif, (t_point){env->perso.position[0],
		env->perso.position[1]}, &count);
	ft_printf("%d\n", count);
	return (count);
}
