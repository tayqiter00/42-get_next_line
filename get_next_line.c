#include "get_next_line.h"

void    free_list(t_list *lst)
{
    t_list  *temp;

    while (lst)
    {
        temp = lst;
        lst = lst->next;
        free(temp->content);
        free(temp);
    }
}

char    *get_next_line(int fd)
{
    char    *buffer;
    char    *line;
    int     bytes_read;
    t_list  *lst;
    t_list  *new;
    t_list  *temp;
    int     i;
    char    *to_free;
    static  char    *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = next_line;
    lst = NULL;
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    bytes_read = 1;
    while (bytes_read)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buffer);
            free_list(lst);
            return (NULL);
        }
        if (bytes_read == 0)
            break ;
        buffer[bytes_read] = '\0';
        new = ft_lstnew(ft_strdup(buffer));
        ft_lstadd_back(&lst, new);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    free(buffer);
    temp = lst;
    while (temp)
    {
        if (!line)
            line = ft_strdup("");
        to_free = line;
        line = ft_strjoin(to_free, temp->content);
        free(to_free);
        temp = temp->next;
    }
    free_list(lst);
    if (!line)
        return (NULL);
    i = 0;
    while (line[i] != '\n' && line[i] != '\0')
        i++;
    if (line[i] == '\0' || line[i + 1] == '\0')
    {
        next_line = NULL;
        return (line);
    }
    next_line = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
    if (!next_line)
        return (NULL);
    line[i + 1] = '\0';
    return (line);
}
