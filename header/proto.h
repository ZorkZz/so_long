/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:24:37 by astachni          #+#    #+#             */
/*   Updated: 2023/01/22 20:51:13 by astachni@st      ###   ########.fr       */
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
int				open_fd(int ac, char **av);
size_t			ft_strslen(char **strs);
int				map_verify(t_perso_env_map *env);
void			*import_enemy(t_perso_env_map *env);

#endif