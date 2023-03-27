/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:35:19 by astachni          #+#    #+#             */
/*   Updated: 2023/03/23 16:26:38 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

ssize_t	verify_char_map1(t_game *env, char c, ssize_t *exit_number, \
		ssize_t *perso_number)
{
	if (c == 'C')
		env->item.nb_item += 1;
	else if (c == 'P')
		*perso_number += 1;
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
	if (perso_number != 1 || exit_number != 1 || env->item.nb_item < 1)
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
	{
		free(str);
		error_before_init("malloc error\n", env);
	}
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
	return (ft_strsfdup(env->map.map_char, strs_temp));
}

void	verif_malloc(char **strs, int size, int fd, t_game *env)
{
	int	i;

	close(fd);
	i = 0;
	(void)env;
	while (strs[i])
		i++;
	if (i != size)
	{
		free_map(strs);
		ft_putendl_fd("ERROR\n", 2);
		exit(1);
	}
}

t_game	map_txt_to_char(int ac, char **av, t_game *env)
{
	int		fd;
	char	*str;
	int		i;

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
	verif_malloc(env->map.map_char, i, fd, env);
	if (!env->map.map_char || !env->map.map_char[0])
		error_before_init("ERROR\n BAD MAP", env);
	env->mlx.map_size[0] = ft_strslen(env->map.map_char) * 64;
	env->mlx.map_size[1] = (ft_strlen(env->map.map_char[0]) - 2) * 64;
	if (verify_char_map(env) == -1)
		error_before_init("ERROR\n BAD MAP", env);
	return (*env);
}
