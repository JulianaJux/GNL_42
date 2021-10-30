/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-alen <jde-alen@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:19:27 by jde-alen          #+#    #+#             */
/*   Updated: 2021/10/30 13:02:08 by jde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*retorna a linha dentro da string ou file completo de acordo com o buffer*/
static char	*find_line(char *str)
{
	int		j;
	char	*line;

	j = 0; /*controle de encontro de achar a linha*/
	if (!str)
		return (NULL); /*proteção de ter mesmo a linha*/
	while (str[j] != '\0' && str[j] != '\n') /*while de iteração enquanto não acha o quebra linha*/
		j++;
	line = (char *)malloc(sizeof(char) * (j + 2)); /*aloca memoria para o fim e o quebra linha*/
	if (!(line)) /* proteção contra má alocação*/
		return (NULL);
	ft_strlcpy(line, str, j + 2); /*copio dentro da linha, o que achei do tamanho de j + fim e quebra linha*/
	if (line [0] == '\0') /*se no inicio já ser o fim*/
	{
		free(line);
		return (NULL); /*e dou free pra não manter alocado o que não precisa*/
	}
	return (line); /*retorno a linha até /n*/
}

static char	*ft_strdup(const char *s1) /*não coube na utils*/
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

/*le e junta as linhas que li em um espaço*/
static char	*read_and_join(int fd, char *str, char *space)
{
	int		reading;
	int		j;
	char	*tmp;

	reading = 1;
	j = 0;
	while (j == 0 && reading != 0) /*loop para manter lendo*/	
	{
		reading = read(fd, space, BUFFER_SIZE); /*aplicação da read em si*/
		if (reading == -1) /*proteção se a read der errado*/
		{
			free (space);
			return (NULL);
		}
		space[reading] = '\0'; /*adiciona dentro do espaço o nulo nos bytes lidos*/
		if (!str)
			str = ft_strdup(""); /*proteção se não tiver mais o que ler*/
		tmp = str; /*jogo com uma temporária*/
		str = ft_strjoin(tmp, space); /*junta a temporaria que é str e o espaço que lemos*/
		free(tmp); /*depois libera ela*/
		if (ft_strchr(str, '\n')) /*condição pra sair é quando encontra \n*/
			j = 1;
	}
	free(space); /*free o que armazenei que eu li*/
	return (str); /*retorna a junção do que li e quanto li*/
}

static char	*new_save(char *str) /*novo backup, depois do /n*/
{
	int		j;
	char	*new_save;

	j = 0;
	while (str[j] != '\0' && str[j] != '\n')
		j++;
	if (str[j] == '\0')
	{
		free(str);
		return (NULL);
	}
	new_save = (char *)malloc(sizeof(char) * (ft_strlen(str) - j + 1));
	if (!new_save)
		return (NULL);
	ft_strlcpy(new_save, str + j + 1, ft_strlen(str) - j + 1);
	free(str);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save_all;
	char		*line;
	char		*file;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!file)
		return (NULL);
	save_all = read_and_join(fd, save_all, file); /*leio e junto no espao*/
	if (!save_all)
		return (NULL);
	line = find_line(save_all); /*dentro do que li, acho a linha*/
	save_all = new_save(save_all); /*salvo o que restou*/
	return (line); /*retorno a linha*/
}
