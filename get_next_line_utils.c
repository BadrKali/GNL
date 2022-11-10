/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kala <bel-kala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:12:49 by bel-kala          #+#    #+#             */
/*   Updated: 2022/11/09 22:12:50 by bel-kala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"get_next_line.h"


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i ++;
	}
	return (i);
}
char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*new;

	i = 0;
	new = malloc((ft_strlen(s1) + 1) * sizeof (char));
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i ++;
	}
	new[i] = '\0';
	return (new);
}
char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (str[i] == (char )c)
			return ((char *)&str[i]);
		i ++;
	}
	return (NULL);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	k = 0;
	new = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i ++;
	}
	while (s2[k] != '\0')
	{
		new[i] = s2[k];
		k ++;
		i ++;
	}
	new[i] = '\0';
	return (new);
}
void	ft_bzero(void *str, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((unsigned char *)str)[i] = '\0' ;
		i ++ ;
	}
}
void	*ft_calloc(size_t nitems, size_t size)
{
	void	*str;

	str = malloc(nitems * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, nitems * size);
	return (str);
}