/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:40:24 by ataboada          #+#    #+#             */
/*   Updated: 2023/10/06 11:06:28 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *storage);
char	*ft_get_current_line(char *storage);
char	*ft_update_storage(char *storage);

/*
int main(void)
{
	int fd_faa, fd_foo;

	fd_faa = open("faa.txt", O_RDONLY);
	fd_foo = open("foo.txt", O_RDONLY);

	char *line = get_next_line(fd_faa);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd_foo);
		printf("%s", line);
		free(line);
		line = get_next_line(fd_faa);
	}

	close(fd_faa);
	close(fd_foo);
}
*/

char	*get_next_line(int fd)
{
	static char	*storage[MAX_O];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > MAX_O)
		return (NULL);
	storage[fd] = ft_read_file(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = ft_get_current_line(storage[fd]);
	storage[fd] = ft_update_storage(storage[fd]);
	if (!*storage[fd])
	{
		free(storage[fd]);
		storage[fd] = NULL;
	}
	return (line);
}

char	*ft_read_file(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 42;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
		{
			if (storage)
				free(storage);
			break ;
		}
		buffer[bytes_read] = '\0';
		storage = ft_merge_strs(storage, buffer);
	}
	free(buffer);
	if (ft_strclen(storage, '\0') > 0 && bytes_read >= 0)
		return (storage);
	return (NULL);
}

char	*ft_get_current_line(char *storage)
{
	char	*line;
	size_t	l_nwl;

	l_nwl = ft_strclen(storage, '\n');
	if (storage[l_nwl] == '\n')
		l_nwl++;
	line = ft_dupstr(storage, l_nwl);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_update_storage(char *storage)
{
	char	*upd_storage;
	size_t	l_nwl;
	size_t	l_nul;

	l_nwl = ft_strclen(storage, '\n');
	l_nul = ft_strclen(storage, '\0');
	if (storage[l_nwl] == '\n')
		l_nwl++;
	upd_storage = ft_dupstr(storage + l_nwl, l_nul - l_nwl + 1);
	if (!upd_storage)
		return (NULL);
	free(storage);
	return (upd_storage);
}
