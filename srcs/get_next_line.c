/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:01:56 by adnajja           #+#    #+#             */
/*   Updated: 2025/06/20 18:23:26 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		j = 0;
		while(str[i] != '\0')
		{
			line[j] = str[i];
			i++;
		}
		free(str);
		return(line);
	}
	if(str[i] == '\0')
	{
		free(str);
		return(NULL);
	}

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
	line = malloc(i + 1);
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
	static char *str;
	int	bytes_read;
	char buffer[BUFFER_SIZE + 1]

	if(BUFFER_SIZE <= 0 || fd < 0)
		return(NULL);
	bytes_read = 1;
	while(!strchr(str, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read < 0)
			return(NULL);
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	line = extract_line(&str);

}