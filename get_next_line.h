/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchauvot <gchauvot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:13:28 by gchauvot          #+#    #+#             */
/*   Updated: 2024/06/11 15:53:32 by gchauvot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdint.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 120
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *dst, char *src, int siz, int alt);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_bzero(void *s, unsigned int n);
void	*ft_calloc(size_t nemb, size_t size);
char	*ft_strchr(char *s, int c);
#endif