/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:07:26 by abdel-ou          #+#    #+#             */
/*   Updated: 2022/11/04 15:46:55 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_big_line(int fd, char *buffer, char *buckup)
{
    int byt_number;
    char *tmp ;
    
    byt_number = 1;
    while (byt_number > 0)
    {
        byt_number = read(fd, buffer, BUFFER_SIZE);
        buffer[byt_number] = '\0';
        if (!buckup)
            buckup = ft_strdup("");
            tmp = buckup;
            buckup = ft_strjoin(tmp,buffer);
            free(tmp);
            tmp = NULL;
            if (check_new_line(buckup) != 0)
                break ;
    }
    return (buckup);
}

char *buckup_finder(char *line)
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
char *get_next_line(int fd)
{
    char *line;
    char *buffer;
    static char *buckup;
    buffer = malloc(BUFFER_SIZE + 1);
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (0);
    
line = ft_big_line(fd, buffer, buckup);   
    free(buffer);
    buffer = 0;
    buckup = buckup_finder(line);
    return (line);
}

int main()
{
int fd = open("file.txt",O_RDONLY);    
printf("%s",get_next_line(fd));
printf("%s",get_next_line(fd));
printf("%s",get_next_line(fd));

    return (0);
}
