/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledos-sa <ledos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:15:52 by ledos-sa          #+#    #+#             */
/*   Updated: 2022/11/18 23:31:52 by ledos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1

int	findn(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	return (i);
}

char	*readline(int fd, char *buf)
{
	char	*aux;
	char	*tpm;

	aux = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		buf = ft_calloc(1, sizeof(char));
	while (read(fd, aux, BUFFER_SIZE))
	{
		tpm = ft_strjoin(buf, aux);
		free(buf);
		buf = tpm;
		if (ft_strchr(tpm, '\n'))
			break ;
	}
	free (aux);
	return (buf);
}

char	*shiftbuffer(char *buf, int start)
{
	int		len;
	char	*newbuf;
	int		i;

	i = 0;
	len = ft_strlen(buf);
	newbuf = malloc((len - start + 1) * sizeof(char));
	start++;
	while (buf[start])
	{
		newbuf[i++] = buf[start++];
	}
	newbuf[i] = '\0';
	free(buf);
	return (newbuf);
}

char	*get_next_line(int fd)
{
	static char	*buffer = 0;
	int			size;
	char		*line;

	buffer = readline(fd, buffer);
	size = findn(buffer);
	line = ft_calloc((size + 1), sizeof(char));
	ft_strlcpy(line, buffer, size + 1);
	buffer = shiftbuffer(buffer, size);
	return (line);
}

int main(int argc, char *argv[])
{
	int fd= open("test.txt",O_RDONLY);
	/* get_next_line(fd); */
	/* get_next_line(fd); */
	printf("final1:%s\n",get_next_line(fd));
	printf("final2:%s\n",get_next_line(fd));
	printf("final2:%s\n",get_next_line(fd));
	printf("final2:%s\n",get_next_line(fd));
	/* printf("%s\n",get_next_line(fd)); */
	return 0;
}
