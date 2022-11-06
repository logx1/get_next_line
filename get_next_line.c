/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:07:26 by abdel-ou          #+#    #+#             */
/*   Updated: 2022/11/06 08:36:24 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		backup = ft_strjoin(backup, buffer);
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
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = ft_big_line(fd, buffer, backup);
	free(buffer);
	if (!line)
		return (0);
	backup = buckup_finder(line);
	return (line);
}

// int main()
// {
// 	int fd = open("file.txt" , O_RDONLY);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	return (0);
// }