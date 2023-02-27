/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:21:49 by astachni@st       #+#    #+#             */
/*   Updated: 2023/02/27 17:11:46 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

ssize_t	ft_strnlen(char *str)
{
	ssize_t	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	check_map(char **map, t_game *env)
{
	if (ft_strslen(map) < 3)
		error_map("ERROR\n BAD MAP\n", env);
	if (ft_strlen(map[0]) < 4)
		error_map("ERROR\n BAD MAP\n", env);
}

void	verif_wall(char	**strs, t_game *env)
{
	ssize_t	i;
	ssize_t	len;

	i = 0;
	while (strs && strs[i])
	{
		if (strs[i][0] != '1' || strs[i][ft_strlen(strs[i]) - 3] != '1')
			error_map("ERROR\n BAD MAP\n", env);
		i++;
	}
	i = 0;
	while (strs && strs[0] && strs[0][i] && strs[0][i] != '\n')
	{
		if (strs[0][i] != '1')
			error_map("ERROR\n BAD MAP\n", env);
		i++;
	}
	i = 0;
	len = ft_strslen(strs) - 1;
	while (strs && strs[len] && strs[len][i] && strs[len][i] != '\n')
	{
		if (strs[len][i] != '1')
			error_map("ERROR\n BAD MAP\n", env);
		i++;
	}
}

void	map_verif(char **strs, t_game *env)
{
	ssize_t	len;
	ssize_t	backup_len;
	ssize_t	i;

	i = 0;
	backup_len = 0;
	while (strs && strs[i])
	{
		len = ft_strnlen(strs[i]);
		if (i != 0)
		{
			if (backup_len != len)
				error_map("ERROR\n BAD MAP\n", env);
		}
		backup_len = len;
		i++;
	}
	verif_wall(strs, env);
	check_map(strs, env);
	is_finish(env);
	i = 0;
	while (strs[i])
		ft_printf("%s", strs[i++]);
}
