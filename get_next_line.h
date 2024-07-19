#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
    char *content;
    struct s_list *next;    
}   t_list;

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char    *ft_strchr(const char *s, int c);
char    *get_next_line(int fd);
void    ft_lstadd_back(t_list **lst, t_list *new);
t_list  *ft_lstnew(char *content);
char    *ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif