/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 05:57:05 by abdel-ou          #+#    #+#             */
/*   Updated: 2022/11/06 06:16:16 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_big_line(int fd, char *buffer, char *backup)
{
	int		byte_read;
	char	*char_temp;

	byte_read = 1;
	while (byte_read != 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read <= 0)
			break ;
		buffer[byte_read] = '\0';
		if (!backup)
			backup = ft_strdup("");
		char_temp = backup;
		backup = ft_strjoin(char_temp, buffer);
		free(char_temp);
		char_temp = NULL;
		if (check_new_line(backup) != 0)
			break ;
	}
	return (backup);
}

char	*buckup_finder(char *line)
{
	size_t		i;
	char		*backup;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[1] == 0)
		return (0);
	backup = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*backup == 0)
	{
		free(backup);
		return (0);
	}
	line[i + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*backup[INT_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = ft_big_line(fd, buffer, backup[fd]);
	free(buffer);
	buffer = 0;
	if (!line)
		return (0);
	backup[fd] = buckup_finder(line);
	return (line);
}
