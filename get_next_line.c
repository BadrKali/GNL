/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:39:58 by bel-kala          #+#    #+#             */
/*   Updated: 2022/11/10 09:28:27 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static char *ft_read_bytes(int fd,char *hide)
{
    char *buf;
    ssize_t read_b;

    if(!hide)
        hide = ft_calloc(1,1);
    buf = ft_calloc(BUFFER_SIZE+1,sizeof(char));
    if(buf == NULL)
        return(NULL);
    read_b = read(fd,buf,BUFFER_SIZE);
    if(read_b == -1)
    {
        free(buf);
        return(NULL);
    }
    buf[read_b]=0;
    //printf("%s",buf);
    if(read_b == -1)
    {
        free(buf);
        return(NULL);
    }
    while(read_b)
    {
        hide = ft_strjoin(hide,buf);
        if(ft_strchr(hide,'\n'))
            break;
        read_b = read(fd,buf,BUFFER_SIZE);
        buf[read_b]=0;
        if(read_b == -1)
        {
            free(buf);
            return(NULL);
        }
    }
    free(buf);
    return(hide);
}

static char *ft_get_first_line(char *string)
{
    char *str;
    int i;

    i = 0;
    while(string[i] && string[i] != '\n')
        i++;

    str = ft_calloc(i+1,sizeof(char));
    if(str == NULL)
        return(NULL);
    i=0;
    while(string[i] != '\0' && string[i] != '\n')
    {
        str[i] = string[i];
        i++;
    }
    if(string[i] == '\0')
        str[i] = '\0';
    else if(string[i] == '\n')
        str[i] = '\n';
    
    return(str);
}
static char *ft_clear_line(char *stach)
{
    char *line;
    int i;
    int j;
    int size;

    i=0;
    j=0;
    while(stach[i] != '\0' && stach[i] != '\n')
        i++;
    size = ft_strlen(stach);
    line = ft_calloc(size - i + 1,sizeof(char));
    while(stach[i] != '\0')
    {
        line[j] = stach[i+1];
        j++;
        i++;
    }
    line[j] = '\0';
    return(line);
}
char *get_next_line(int fd)
{
    static char *hide;
    char *line;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);

    if(!(hide = ft_read_bytes(fd,hide)))
        return(NULL);
    line = ft_get_first_line(hide);
    hide = ft_clear_line(hide);
    return(line);
}
/*
int main()
{
    int fd;
    char *line;
    int i;
    i = 0;
    fd = open("myfile.txt",O_RDONLY);
    while(i<1)
    {
        //line = get_next_line(fd);
        printf("Line [%d] :%s", i,get_next_line(fd));
        i++;
    }
    return(0);
}
*/