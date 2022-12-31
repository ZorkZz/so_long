/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:24:37 by astachni          #+#    #+#             */
/*   Updated: 2022/12/31 02:58:34 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

int		error(int code, char *message);
int		close_mlx(t_var_env *mlx);
int		event(int key, t_var_env *perso);
void	*import_sprite_charactere(t_var_env *mlx, t_perso *character);
void	*import_map(t_var_env *mlx, t_img *map);

#endif