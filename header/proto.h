/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:24:37 by astachni          #+#    #+#             */
/*   Updated: 2023/01/12 18:12:54 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

int			error(int code, char *message);
int			close_mlx(t_perso_env *mlx);
int			event(int key, t_perso_env *perso);
void		*import_sprite_charactere(t_perso_env *mlx);
void		*import_map(t_perso_env *mlx, t_img *map);
t_img		map_charact(t_img *map);
t_perso_env	perso_charact(t_perso_env *perso);
void		*free_all(int value, t_perso_env *perso, t_img *map);
t_img		read_map(int ac, char **av, t_img *map, t_perso_env *mlx);

#endif