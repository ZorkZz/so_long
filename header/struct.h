/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:27:02 by astachni          #+#    #+#             */
/*   Updated: 2022/12/30 20:08:50 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_var_env
{
	void	*init;
	void	*win;
}	t_var_env;

typedef struct s_character
{
	void	*path;
	void	*img_ptr;
}	t_character;

typedef struct s_img
{
	void			*img;
	struct t_img	*next;
}	t_img;

#endif