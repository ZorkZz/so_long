/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:24:37 by astachni          #+#    #+#             */
/*   Updated: 2023/01/19 18:08:59 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

int				error(int code, char *message);
int				close_mlx(t_perso_env_map *env);
int				event(int key, t_perso_env_map *env);
void			*import_sprite_charactere(t_perso_env_map *env);
void			*import_map(t_perso_env_map *env);
t_perso_env_map	map_charact(t_perso_env_map *env);
t_perso_env_map	perso_charact(t_perso_env_map *env);
void			*free_all(int value, t_perso_env_map *env);
t_perso_env_map	read_map(t_perso_env_map *env);
char			**parse_map(t_perso_env_map *env, char *strs);
t_perso_env_map	map_txt_to_char(int ac, char **av, t_perso_env_map *env);
t_perso_env_map	*verify_moov_char(t_perso_env_map *env, int moov);
void			*import_item(t_perso_env_map *env);
t_perso_env_map	item_charact(t_perso_env_map *env);
t_perso_env_map	add_charac(t_perso_env_map *env);
void			*import_exit(t_perso_env_map *env);
void			free_map(char **strs);

#endif