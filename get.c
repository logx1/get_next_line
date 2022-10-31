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
	line = malloc(sizeof(char) * (BUFFER_SIZE));
	char buffer;
	int i = 0;
	int r = read(fd,&buffer,1);
	
		
	while (r > 0 && r < BUFFER_SIZE + 1 && buffer != '\n')
	{
		line[i] = buffer;
		r += read(fd,&buffer,1);
		if (r > BUFFER_SIZE)
		{
			r = 1;
			line = ft_realloc(line,BUFFER_SIZE);
		}
		i++;
	}
line[i] = '\0';
return (line);
}

int main()
{
int fd;
fd = open("file.txt",O_RDONLY);
printf("%s",get_next_line(fd));




	return (0);
}
