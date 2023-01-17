/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:27:02 by astachni          #+#    #+#             */
/*   Updated: 2023/01/17 20:02:56 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_item
{
	void	*itm_ptr;
	char	*path;
	int		position[2];
	int		size;
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
	int		can_moov;
}	t_perso;

typedef struct s_env
{
	void	*init;
	void	*win;
}	t_env;

typedef struct s_perso_env_map
{
	t_img	map;
	t_item	item;
	t_perso	perso;
	t_env	mlx;
}	t_perso_env_map;

#endif