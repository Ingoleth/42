#include "FdF.h"

static t_bool check_if_number(char *content)
{
    int i;

    i = 0;
    if (content[i] == '-')
        i++;
    while (content[i])
    {
        if (!ft_isdigit(content[i]))
        {
            printf("Wrong map input!\n");
            return(false);
        }
        i++;
    }
    return (true);
}

static void    clean_and_exit(t_list **lines, int *line, char **content, char *str)
{
    t_list *aux;

    free(str);
    free(line);
    ft_array_clear((void **)content, free);
    aux = *lines;
    while (aux)
    {
        ft_array_clear(aux->content, free);
        aux = aux->next;
    }
    ft_lstclear(lines, 0);
    exit(-1);
}

static void    get_map_line(char *str, t_list **lines)
{
    int *line;
    char **elements;
    int i;

    i = 0;
    elements = ft_split(str, ' ');
    while (elements[i])
        i++;
    line = ft_alloc( i + 1, sizeof(int));
    if (line == NULL)
    {
        ft_array_clear((void **)elements, free);
        exit(-1);
    }
    line[0] = i;
    i = 0;
    while (elements[i])
    {
        line[i + 1] = ft_atoi(elements[i]);
        if(!check_if_number(elements[i]))
            clean_and_exit(lines, line, elements, str);
        i++;
    }
    ft_array_clear((void **)elements, free);
    ft_lstadd_back(lines, ft_lstnew(line));
}

int **load_map_lines(t_list *lines)
{
    int **map;
    t_list *aux;
    int i;

    map = ft_alloc(ft_lstsize(lines), sizeof(int *));
    if (!(map))
    {
        ft_lstclear(&lines, free);
        exit(-1);
    }
    i = 0;
    aux = lines;
    while (aux)
    {
        map[i] = aux->content;
        aux = aux->next;
        i++;
    }
    ft_lstclear(&lines, NULL);
    return (map);
}

int **get_map()
{
    int     **map;
    char    *str;
    t_list  *lines;
    int     i;
    int     fd;

    lines = NULL;
    fd = open("map", O_RDONLY);
    while (true)
    {
        i = get_next_line(fd, &str);
        get_map_line(str, &lines);
        free(str);
        if (i == 0)
            break;
    }
    close(fd);
    map = load_map_lines(lines);
    return (map);
}