# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd);
int	ft_strlen(char *str);
char *ft_strdup(char *str);
int check_new_line(char *str);
char *ft_strjoin(char *str1, char *str2);
char *ft_substr(char *s, int start, size_t len);
char *buckup_finder(char *line);

#endif
