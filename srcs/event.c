/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:39:14 by astachni          #+#    #+#             */
/*   Updated: 2022/12/30 14:56:58 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	event(int key, t_var_env *mlx)
{
	if (key == 'w')
		ft_printf("%c\n", key);
	else if (key == 'a')
		ft_printf("%c\n", key);
	else if (key == 's')
		ft_printf("%c\n", key);
	else if (key == 'd')
		ft_printf("%c\n", key);
	else if (key == 65307)
	{
		close_mlx(mlx);
		ft_printf("%s\n", "fermeture de la fenetre");
	}
	else
		ft_printf("%s\n", "cle non reconnu");
	return (key);
}
