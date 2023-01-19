/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:24:22 by marvin@42.f       #+#    #+#             */
/*   Updated: 2022/12/30 16:11:52 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i++])
		;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || (dest == NULL && src == NULL))
		return (dest);
	while (i < n)
	{
		*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char			*dest;
	const size_t	len = ft_strlen((char *)src);

	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	dest = ft_memcpy(dest, src, (size_t)len);
	dest[len] = '\0';
	return (dest);
}
