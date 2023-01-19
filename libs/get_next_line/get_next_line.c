/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:03:49 by astachni          #+#    #+#             */
/*   Updated: 2023/01/12 17:16:48 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next.h"

size_t	take_read(char *str, char *buffer, int read_buffer, size_t read_value)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str && str[i])
	{
		j = 0;
		while (str[i] && buffer[j] && str[i] == buffer[j])
		{
			i++;
			j++;
		}
		if (str[i] && str[i] != buffer[j])
			i = i - j + 1;
	}
	j += read_buffer;
	if (j >= read_value)
		j = 0;
	return (j);
}

char	*read_error(char *str, char *buffer, int read_value)
{
	if (read_value == -1)
		return (ft_bzero(buffer), NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*str;
	static char		buffer[MAX_FD][BUFFER_SIZE + 1];
	static ssize_t	read_value;
	static size_t	read_buffer = 0;

	if (fd < 0)
		return (NULL);
	str = NULL;
	while (str == NULL || str[ft_strlenn(str) - 1] != '\n')
	{
		if (read_buffer == 0 || read_buffer >= BUFFER_SIZE)
		{
			ft_bzero(buffer[fd]);
			read_value = read(fd, buffer[fd], BUFFER_SIZE);
		}
		if (read_value < 1)
			return (read_error(str, buffer[fd], read_value));
		str = ft_strfjoin(str, &buffer[fd][read_buffer], (size_t)read_value);
		if (!str)
			return (NULL);
		read_buffer = take_read(str, &buffer[fd][read_buffer], read_buffer, \
			read_value);
	}
	return (str);
}
