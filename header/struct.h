/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:27:02 by astachni          #+#    #+#             */
/*   Updated: 2023/01/02 22:51:16 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_perso_env
{
	void	*init;
	void	*win;
	char	*path;
	void	*img_ptr;
	int		size;
	int		*position;
}	t_perso_env;


typedef struct s_img
{
	char			*path;
	void			*img_ptr;
	int				size;
	int				*position;
	struct t_img	*next;
}	t_img;



#endif