/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:27:02 by astachni          #+#    #+#             */
/*   Updated: 2022/12/31 02:54:17 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_var_env
{
	void	*init;
	void	*win;
}	t_var_env;

typedef struct s_perso
{
	char	*path;
	void	*img_ptr;
	int		size;
	int		*position;
}	t_perso;

typedef struct s_img
{
	char			*path;
	void			*img_ptr;
	int				size;
	struct t_img	*next;
}	t_img;



#endif