/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:39:08 by astachni          #+#    #+#             */
/*   Updated: 2023/01/29 20:12:55 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

//return map free
char	**ft_strsfdup(char **map, char **str)
{
	size_t	len;
	size_t	i;

	free_map(map);
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

//return map don't free
char	**ft_strsdup(char **map, char **str)
{
	size_t	len;
	size_t	i;

	free_map(map);
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
	return (map);
}

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
