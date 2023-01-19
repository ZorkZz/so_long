/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:04:55 by astachni          #+#    #+#             */
/*   Updated: 2023/01/12 17:16:29 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_H

# define GET_NEXT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 1025
# endif

char	*get_next_line(int fd);
size_t	ft_strlenn(char const *str);
void	ft_bzero(char *str);
char	*ft_strfjoin(char *s1, char const *buffer, int read_value);

#endif