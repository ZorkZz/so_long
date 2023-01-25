/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:32:20 by astachni          #+#    #+#             */
/*   Updated: 2023/01/25 20:36:30 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	error(int code, char *message, t_game *env)
{
	free_map(env->map.map_char);
	ft_printf("%s: %d", message, code);
	exit(-1);
	return (code);
}
