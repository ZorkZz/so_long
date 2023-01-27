/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:24:37 by astachni          #+#    #+#             */
/*   Updated: 2023/01/27 22:11:45 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

int				error(int code, char *message, t_game *env);
int				close_mlx(t_game *env);
int				event(int key, t_game *env);
void			import_sprite_charactere(t_game *env);
void			import_map(t_game *env, int choice);
void			*free_all(int value, t_game *env);
t_game			read_map(t_game *env);
char			**parse_map(t_game *env, char *strs);
t_game			map_txt_to_char(int ac, char **av, t_game *env);
t_game			*verify_moov_char(t_game *env, int moov);
void			import_item(t_game *env);
t_game			add_charac(t_game *env);
void			import_exit(t_game *env);
void			free_map(char **strs);
int				open_fd(int ac, char **av);
size_t			ft_strslen(char **strs);
void			import_enemy(t_game *env);
char			**ft_strsdup(char **map, char **str);
void			map_verif(char **strs, t_game *env);
void			is_finis(t_game *env);

#endif