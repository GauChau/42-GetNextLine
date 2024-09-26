/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:13:28 by gchauvot          #+#    #+#             */
/*   Updated: 2024/06/11 15:59:41 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include "get_next_line.h"

int	ft_strlen(char *dst, char *src, int siz, int alt)
{
	int	i;

	i = 0;
	if (alt == 1)
	{
		if (!dst)
			return (0);
		while (dst[i] != '\0')
			i++;
		return (i);
	}
	if (alt == 2)
	{
		while (src[i] != '\0' && i + 1 < siz)
		{
			dst[i] = src[i];
			i++;
		}
		if (siz > 0)
			dst[i] = '\0';
	}
	return (i);
}

void	*ft_calloc(size_t nemb, size_t size)
{
	void	*ret;

	if (size && SIZE_MAX / size < nemb)
	{
		return (NULL);
	}
	ret = (void *)malloc(nemb * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, nemb * size);
	return (ret);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (((char *)(&s[i])));
		i++;
	}
	if (s[i] == c && c == '\0')
		return ((char *) &(s[i]));
	return (0);
}

void	*ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*array;

	i = 0;
	j = 0;
	array = (char *)malloc((ft_strlen(s1, 0, 0, 1)
				+ ft_strlen(s2, 0, 0, 1) + 1) * sizeof(char));
	if (!array)
		return (0);
	while (s1[i] != '\0')
	{
		array[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		array[j] = s2[i];
		i++;
		j++;
	}
	array[j] = '\0';
	return (array);
}
