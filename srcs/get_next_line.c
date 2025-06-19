/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnajja <adnajja@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:01:56 by adnajja           #+#    #+#             */
/*   Updated: 2025/06/11 20:02:52 by adnajja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
}