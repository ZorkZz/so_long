/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:35:33 by astachni@st       #+#    #+#             */
/*   Updated: 2023/01/18 18:58:15 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

size_t	ft_strslen(char **strs)
{
	size_t	i;

	if (strs == NULL)
		return (0);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}

void	free_map(char **strs)
{
	size_t	i;

	i = 0;
	while (strs && strs[i])
	{
		free(strs[i]);
		i++;
	}
	if (strs)
		free(strs);
}

char	**cpy_in_struct(char **map, char **str)
{
	size_t	len;
	size_t	i;

	len = ft_strslen(str);
	map = malloc((len + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (map && str && str[i] != NULL && i < len)
	{
		map[i] = ft_strdup(str[i]);
		i++;
	}
	map[i] = NULL;
	free_map(str);
	return (map);
}

char	**parse_map(t_perso_env_map *env, char *str)
{
	char	**strs_temp;
	size_t	len;
	size_t	i;

	if (!str)
		return (NULL);
	len = ft_strslen(env->map.map_char);
	strs_temp = malloc((len + 2) * sizeof(char *));
	if (!strs_temp)
		return (NULL);
	i = 0;
	while (env->map.map_char && env->map.map_char[i])
	{
		strs_temp[i] = ft_strdup(env->map.map_char[i]);
		i++;
	}
	if (str)
		strs_temp[i] = ft_strdup(str);
	strs_temp[len + 1] = NULL;
	return (cpy_in_struct(env->map.map_char, strs_temp));
}

t_perso_env_map	map_txt_to_char(int ac, char **av, t_perso_env_map *env)
{
	int		fd;
	char	*str;
	int		i;

	env->map.map_char = NULL;
	fd = open_fd(ac, av);
	if (fd < 0)
		return (*env);
	str = get_next_line(fd);
	i = 0;
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
	close(fd);
	return (*env);
}
