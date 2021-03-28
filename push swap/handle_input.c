#include "libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef enum	e_error_code
{
    not_nb = 1,
    repeated,
    max_int = 2147483647,
    min_int = -2147483648
}	            t_error_code;

t_bool  is_number(char *line)
{
    int i;

    i = 0;
    if (ft_strchr("+-", line[0]))
        i++;
    while (line[i])
    {
        if (!ft_isdigit(line[i]))
            return (false);
        i++;
    }
    return (true);
    
}

t_bool is_repeated(int nb, t_list *array_list)
{
    if (array_list)
        while (array_list)
        {
            if (((int *)array_list->content)[0] == nb)
                return (true);
            array_list = array_list->next;
        }
    return (false);
}

static void fill_array(int **array, t_list *array_list)
{
    int i;

    i = 0;
    array[0] = ft_alloc(ft_lstsize(array_list), sizeof(int));
    if (!array[0])
        return ;
    while (array_list)
    {
        array[0][i] = ((int *)array_list->content)[0];
        array_list = array_list->next;
        i++;
    }
}

static void add_nb_to_array(char *line, t_list **array_list)
{
    int         error;
    int         *nb;
    long int    aux; 

    error = 0;
    if (!is_number(line))
        error = not_nb;
    else
    {
        aux = ft_atoi(line);
        free(line);  
        if (aux > max_int || aux < min_int)
            error = max_int;
        else if (is_repeated(aux, array_list[0]))
                error = repeated;
    }
    if (!error)
    {
        nb = ft_alloc(1, sizeof(int));
        if (nb)
        {
            nb[0] = aux;
            ft_lstadd_back(array_list, ft_lstnew(nb));
        }
    }
    else
    {
        ft_printf(STDERR_FILENO, "Error\n");
        ft_lstclear(array_list, free);
        exit(-1);
    }
}

char *read_input(int fd)
{
    char *line;
    char *aux;
    int bytes_read;
    char buffer[2];

    line = ft_strdup("");
    buffer[1] = 0; //Not 100% sure this is needed...
    while (true)
    {
        bytes_read = read(fd, buffer, 1);
        if (!bytes_read || buffer[0] == '\n')
        break ;
        aux = ft_strjoin(line, buffer);
        free(line);
        line = aux;
    }
    return (line);
}

int *handle_input(int fd)
{
    t_list *array_list;
    char *line;
    int *array;

    array_list = NULL;
    if (fd == STDIN_FILENO)
        printf("Please input the values for the array:\n");
    while (true)
    {
        line = read_input(fd);
        if (!ft_strncmp(line, "", 1))
        {
            free(line);
            break ;
        }
        add_nb_to_array(line, &array_list);
    }
    fill_array(&array, array_list);
    ft_lstclear(&array_list, free);
    return (array);
}

int main (int arc, char **argv)
{
    int *array;
    int i;
    //int fd;

    //fd = open("test", O_RDONLY);
    if (arc == 1)
        return (0);
    if (!ft_strncmp(argv[1], "-ci", 4))
        array = handle_input(STDIN_FILENO);
    else
        return (0);
    

    i = 0;
    while (array[i])
    {
        printf("* %d\n", array[i]);
        i++;
    }
    
}