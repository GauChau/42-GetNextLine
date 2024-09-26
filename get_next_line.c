/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:13:20 by gchauvot          #+#    #+#             */
/*   Updated: 2024/06/12 12:38:34 by gchauvot         ###   ########.fr       */
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
//#define BUFFER_SIZE 3
int		ft_strlen(char *dst, char *src, int siz, int alt);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_bzero(void *s, unsigned int n);
void	*ft_calloc(size_t nemb, size_t size);
char	*ft_strchr(char *s, int c);

char	*freejoin(char *res, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(res, buffer);
	free(res);
	return (temp);
}

char	*readfile(int fd, char *res)
{
	int		bytes_read;
	char	*lecture;

	if (!res)
		res = ft_calloc(1, sizeof(char));
	lecture = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!lecture)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, lecture, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(res);
			free(lecture);
			return (NULL);
		}
		lecture[bytes_read] = '\0';
		res = freejoin(res, lecture);
		if (ft_strchr(lecture, '\n'))
			break ;
	}
	free(lecture);
	return (res);
}

char	*ft_currentl(char *buffer)
{
	int		i;
	int		j;
	char	*ligne;

	i = 0;
	j = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	ligne = ft_calloc(i + 2, sizeof(char));
	while (j < i + 1 && buffer[j] != '\0')
	{
		ligne[j] = buffer[j];
		j++;
	}
	return (ligne);
}

char	*nextline(char *buffer)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp = ft_calloc(ft_strlen(
				ft_strchr(buffer, '\n'), 0, 0, 1) + 1, sizeof(char));
	if (!temp)
		return (NULL);
	j = 0;
	while (buffer[i] != '\0')
	{
		i++;
		temp[j] = buffer[i];
		j++;
	}
	free(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	statik[BUFFER_SIZE];
	char		*buffer;
	char		*res;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
	{
		buffer = NULL;
		ft_bzero(statik, BUFFER_SIZE);
		return (buffer);
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	if (statik[0] != '\0')
		ft_strlen(buffer, statik, BUFFER_SIZE, 2);
	if (!ft_strchr(buffer, '\n'))
		buffer = readfile(fd, buffer);
	res = ft_currentl(buffer);
	buffer = nextline(buffer);
	if (buffer)
		ft_strlen(statik, buffer, BUFFER_SIZE, 2);
	if (buffer)
		free (buffer);
	return (res);
}
// int main(void)
// {
// 	int fd = open("file.txt", O_RDWR);
// 	if(!fd)
// 		return 0;
// 	char *l;
// 	int i=0;
// 	while(i<4)
// 	{
// 		l = get_next_line(fd);
// 		printf("%s \n", l);
// 				free(l);
// 		i++;
// 	}
// 	/*printf("l: -%s-\n", get_next_line(fd));
// 	printf("l: -%s-\n", get_next_line(fd));
// 	printf("l: -%s-\n", get_next_line(-1));
//  close(fd);fd=open("read_error.txt", O_RDWR);
// 	printf("l: -%s-\n", get_next_line(fd));
// 	*/
// 	return (0);
// }
