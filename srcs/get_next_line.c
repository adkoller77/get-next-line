/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:01:56 by adnajja           #+#    #+#             */
/*   Updated: 2025/07/23 20:25:35 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_str(char *str)
{
	int	j;
	int	i;
	char	*line;

	i = 0;
	if(str == NULL)
		return(NULL);
	while(str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	if(str[i] == '\n')
	{
		i++;
		line = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
		if(!line)
			return(NULL);
		j = 0;
		while(str[i] != '\0')
		{
			line[j] = str[i];
			j++;
			i++;
		}
		free(str);
		str = NULL;
		return(line);
	}
	return(NULL);
}

char *extract_line(char **str)
{
    int i;
	int j;
    char *line;
    
	i = 0;
	if(*str == NULL)
		return(NULL);
	while((*str)[i] != '\n' && (*str)[i] != '\0')
	{
		i++;
	}

	if ((*str)[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if(!line)
		return(NULL);
	j = 0;
	while(j < i)
	{
		line[j] = (*str)[j];
		j++;
	}
	line[j] = '\0';
	return(line);
}


char *get_next_line(int fd)
{
	char	*line;
	static char *str;
	int	bytes_read;
	char buffer[BUFFER_SIZE + 1];

	if(BUFFER_SIZE <= 0 || fd < 0)
		return(NULL);
	if(!str)
		str = ft_strdup("");
	bytes_read = 1;
	while(!ft_strchr(str, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read < 0)
		{
			free(str);
			str = NULL;
			return(NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
		if(!str)
			return(NULL);
	}
	line = extract_line(&str);
	str = clean_str(str);
	return(line);
}

