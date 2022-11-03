/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ou <abdel-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 07:18:28 by abdel-ou          #+#    #+#             */
/*   Updated: 2022/11/03 13:57:56 by abdel-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int check_new_line(char *str)
{
	int i = 0;
	while (str[i])
	{
		if(str[i] == '\n')
			return (1);
		i++;
	}
	return (-1);
}

char *ft_realloc(char *oldpointer,int size_add)
{
	int i;
	int j;
	char *newpointer;
	j = ft_strlen(oldpointer);
	i = 0;
		newpointer = (char *)malloc(sizeof(char) * (size_add + j));

	while (i <= j)
	{
		newpointer[i] = oldpointer[i];
		i++;
	}
	

return newpointer;

}

// char *line(char *line, int buffer_size)
// {
// 	int i = 0;
// 	int r = read(fd,&buffer,1);
// while (r > 0 && r <= BUFFER_SIZE)
// 	{
// 		line[i] = buffer;
// 		if (buffer == '\n')
// 			break;
// 		r += read(fd,&buffer,1);
// 		i++;
// 	}
// }



char *get_next_line(int fd)
{
	char *line;
	static char *buckup;
	line = malloc(sizeof(char) * (BUFFER_SIZE));
	buckup = malloc(sizeof(char) * BUFFER_SIZE);
	char buffer;
	int i = 0;
	int j = 0;
	int r = 0;
	
	while (r < BUFFER_SIZE + 1)
	{
		r += read(fd,&buffer,1);
		if (check_new_line(line) == -1)
			line[i] = buffer;
		if (check_new_line(line) == 1)
		{
				buckup[j] = buffer;
				j++;
		}
		
		
		if (r > BUFFER_SIZE  && check_new_line(line) == -1)
		{
			r = 1;
			line = ft_realloc(line,BUFFER_SIZE);
		}
		i++;
	}
line[i] = '\0';
buckup[j]= 0;
printf("%s",line);
printf("%s",buckup);

return (line);
}


char *ft_strjoin(char *str1, char *str2)
{
	char *final_str = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2)) + 1); 
	int i = 0;
	while (i < ft_strlen(str1))
	{
		final_str[i] = str1[i];
		i++;
	}
	i = 
	while (i < (ft_strlen(str1) + ft_strlen(str2)))
	{
		final_str[i] = str2[i];
		i++;
	}
	final_str[i] = 0;
	return (final_str);
}

int main()
{
// int fd;
// fd = open("file.txt",O_RDONLY);
// get_next_line(fd);
char str1[] = "abdelmajid ";
char str2[] = "eloualy";
printf("%s",ft_strjoin(str1,str2));
	return (0);
}
