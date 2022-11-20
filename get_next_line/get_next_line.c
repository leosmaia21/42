/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:14:04 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/20 23:29:26 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char	*read_line(int fd, char *buf)
{
	char	*aux;
	char	*tpm;
	char	b_read;

	b_read = 1;
	if (!buf)
		buf = ft_calloc(1, 1);
	aux = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (b_read != 0 && !ft_strchr(buf, '\n'))
	{
		b_read = read(fd, aux, BUFFER_SIZE);
		if (b_read < 0)
		{
			free(aux);
			return (NULL);
		}
		tpm = ft_strjoin(buf, aux);
		ft_bzero(aux, BUFFER_SIZE + 1);
		free(buf);
		buf = tpm;
	}
	free(aux);
	return (buf);
}

int	findn(char	*buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (++i);
		i++;
	}
	return (i);
}

char	*get_line(char *buf)
{
	char	*line;
	int		i;
	int		len;

	len = findn(buf);
	i = 0;
	line = ft_calloc(len + 1, sizeof(char));
	while (buf[i] && i < len)
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*shiftbuffer(char *buf)
{
	int		i;
	int		newindex;
	char	*newbuf;

	i = 0;
	newindex = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	newbuf = ft_calloc(ft_strlen(&buf[++i]) + 1, sizeof(char));
	while (buf[i])
		newbuf[newindex++] = buf[i++];
	newbuf[newindex] = '\0';
	free(buf);
	return (newbuf);
}

char	*get_next_line(int fd)
{
	static char	*buffer = 0;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = shiftbuffer(buffer);
	return (line);
}

int main(int argc, char *argv[])
{
	int fd = open ("test.txt", O_RDONLY);
	char *s1 = get_next_line(fd);
	char *s2 = get_next_line(fd);
	char *s3 = get_next_line(fd);
	char *s4 = get_next_line(fd);
	free(s1);
	free(s2);
	free(s3);
	free(s4);
	return 0;
}
