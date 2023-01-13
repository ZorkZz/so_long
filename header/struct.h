/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni@student.42lyon.fr <astachni>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:27:02 by astachni          #+#    #+#             */
/*   Updated: 2023/01/13 20:47:43 by astachni@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img
{
	char	*path;
	void	*img_ptr;
	int		size;
	int		*position;
}	t_img;

typedef struct s_perso
{
	char	*path;
	void	*img_ptr;
	int		size;
	int		*position;
}	t_perso;

typedef struct s_env
{
	void	*init;
	void	*win;
}	t_env;

typedef struct s_perso_env_map
{
	t_img	map;
	t_perso	perso;
	t_env	mlx;
}	t_perso_env_map;

#endif