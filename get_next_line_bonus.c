/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-alen <jde-alen@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:59:58 by jde-alen          #+#    #+#             */
/*   Updated: 2021/10/17 21:10:44 by jde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_free(char **str)
{
	if(str)
	{
		free(*str);
		*str = 0;
	}
}

static char *ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	size_t	j;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (j < len)
	{
		str[j] = s1[j];
		j++;
	}
	str[len] = '\0';
	return (str);
}

static int	ft_read(int fd, char **buff, int *b_read)
{
	int	j;

	j = read(fd, *buff, BUFFER_SIZE);
	*b_read = j;
	return (j);
}

static char *ft_get_the_line(char **str)
{
	size_t	j;
	char	*res;
	char	*tmp;

	j = 0;
	while ((*str)[j] && (*str)[j] != '\n')
		j++;
	if ((*str)[j])
	{
		res = ft_substr(*str, 0, j + 1);
		tmp = ft_strdup(*str + j +1);
		ft_free(str);
		if (tmp[0] != '\0')
			*str = tmp;
		else
			ft_free(&tmp);
	}
	else
	{
		res = ft_strdup(*str);
		ft_free(str);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res[1024];
	char		*buff;
	char		*tmp;
	int			b_read;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (0);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	while (ft_read (fd, &buff, &b_read) > 0)
	{
		buff[b_read] = 0;
		if (!res[fd])
			res[fd] = ft_bzero(0)
			tmp = ft_strcat(res[fd], buff);
			ft_free(&res[fd]);
			res[fd] = tmp;
			if (ft_strchr(buff, '\n'))
				break;
	}
	ft_free(&buff);
	if (b_read < 0 || (b_read == 0 && !res[fd]))
		return (NULL);
	return (ft_get_the_line(&res[fd]));
}
