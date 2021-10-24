/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-alen <jde-alen@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:19:27 by jde-alen          #+#    #+#             */
/*   Updated: 2021/10/24 15:08:23 by jde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*retorna a linha dentro da string ou file completo de acordo com o buffer*/
static char	*find_line(char *str)
{
	int j;
	char *line;

	j = 0;

	if (!(str))
		return (0);
	while (*str != '\0' || *str != '\n')
		j++;
	line = (char *)malloc(sizeof(char) * (j + 2));
	if (!(line))
		return (NULL);
	ft_strlcpy(line, str, j + 2);
	if (line [0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/*le e junta as linhas que li em um espaço*/
static char *read_and_join(int fd, char *str, char *space)
{
	int	reading;
	int	j;
	char *tmp;

	reading = 1;
	j = 0;
	space = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!space)
		return(NULL);
		while (j == 0 && reading != 0)
	{
		reading = read(fd, space, BUFFER_SIZE);
		if (reading == - 1)
		{
			free(space);
			return (NULL);
		}
		space[reading] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, space);
		free(tmp);
		if(ft_strchr(str, '\n'))
			j = 1;
	}
	free(space);
	return (str);
}

static char	*new_save(char *str)
{
	int	j;
	char	*new_save;

	j = 0;
	while(str[j] != '\0' && str[j] != '\n')
		j++;
	new_save = (char *)malloc(sizeof(char) * (ft_strlen(str) - j + 1));
	if (!new_save)
		return (NULL);
	ft_strlcpy(new_save, str + 1, ft_strlen(str) - j + 1);
	free(str);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char *save_all;
	char		*line;
	char		*file;

	line = NULL;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save_all = read_and_join(fd, save_all, file);
	if (!save_all)
		return (NULL);
	line = find_line(save_all);
	save_all = new_save(save_all);
	return (line);
}