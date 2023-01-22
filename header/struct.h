/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:27:02 by astachni          #+#    #+#             */
/*   Updated: 2023/01/20 20:32:46 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_enemy
{
	void	*img_ptr;
	char	*path;
	int		position[2];
	int		size;
}	t_enemy;

typedef struct s_exit
{
	void	*img_ptr;
	char	*path;
	int		position[2];
	int		size;
}	t_exit;

typedef struct s_item
{
	void	*itm_ptr;
	char	*path;
	int		position[2];
	int		size;
	ssize_t	collected;
	ssize_t	nb_item;
}	t_item;

typedef struct s_img
{
	char	*path;
	char	**map_char;
	char	**img_ptr;
	int		size;
	int		position[2];
}	t_img;

typedef struct s_perso
{
	char	*path;
	void	*img_ptr;
	int		size;
	int		position[2];
	size_t	moov;
	int		can_moov;
}	t_perso;

typedef struct s_env
{
	void	*init;
	void	*win;
}	t_env;

typedef struct s_perso_env_map
{
	t_enemy	enemy;
	t_exit	exit;
	t_img	map;
	t_item	item;
	t_perso	perso;
	t_env	mlx;
}	t_perso_env_map;

#endif