/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:35:33 by astachni@st       #+#    #+#             */
/*   Updated: 2023/01/26 17:19:43 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

ssize_t	verify_char_map1(t_game *env, char c, ssize_t *exit_number, \
		ssize_t *perso_number)
{
	if (c == 'C')
			env->item.nb_item += 1;
	else if (c == 'P')
			perso_number += 1;
	else if (c == 'E')
		*exit_number += 1;
	else if (c != '0' && c != '1' && c != 'N' && c != '\n' && c != '\0')
		return (-1);
	return (0);
}

ssize_t	verify_char_map(t_game *env)
{
	ssize_t	exit_number;
	ssize_t	perso_number;
	ssize_t	i;
	ssize_t	j;

	exit_number = 0;
	perso_number = 0;
	env->item.nb_item = 0;
	i = 0;
	while (env->map.map_char && env->map.map_char[i])
	{
		j = 0;
		while (env->map.map_char[i] && env->map.map_char[i][j])
		{
			if (verify_char_map1(env, env->map.map_char[i][j], \
				&exit_number, &perso_number) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	if (perso_number != 1 && exit_number != 1 && env->item.nb_item < 1)
		return (-1);
	return (env->item.nb_item);
}

char	**parse_map(t_game *env, char *str)
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
	return (ft_strsdup(env->map.map_char, strs_temp));
}

t_game	map_txt_to_char(int ac, char **av, t_game *env)
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
	env->mlx.map_size[0] = ft_strslen(env->map.map_char) * 64;
	env->mlx.map_size[1] = (ft_strlen(env->map.map_char[0]) - 2) * 64;
	close(fd);
	if (verify_char_map(env) == -1)
		error(78, "ERROR\n BAD MAP", env);
	return (*env);
}
