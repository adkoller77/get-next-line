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
	
}