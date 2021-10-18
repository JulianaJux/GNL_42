/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-alen <jde-alen@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:01:00 by jde-alen          #+#    #+#             */
/*   Updated: 2021/10/17 21:16:16 by jde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	j;

	j = 0;
	while (*s != '\0')
	{
		j++;
		s++;
	}
	return (j);
}

size_t	*ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	t;

	j = 0;
	t = 0;
	while (dst[j] && j < dstsize)
		j++;
	while ((src[t]) && ((j + t + 1) < (dstsize)))
	{
		dst[j + t] = src[t];
		t++;
	}
	if (j != dstsize)
		dst[j + t] = '\0';
	return (j + ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	int	j;

	if (!s)
		return (NULL);
	j = 0;
	while (s[j])
	{
		if (s[j] == (char)c)
			return ((char *)(s + j));
		j++;
	}
	if (s[j] == (char)c)
		return ((char *)(s + j));
	return (NULL);
}

char	*ft_substr(const char *str, size_t start, size_t len)
{
	char	*res;
	size_t	i;

	if (!str)
		return (0);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	i = 0;
	while (start < len)
		res[i++] = str[start++];
	res[i] = 0;
	return (res);
}

char	*ft_bzero(size_t size)
{
	char	*j;
	size_t	i;

	j = (char *)malloc(sizeof(char) * (size + 1));
	if (!j)
		return (0);
	i = 0;
	while (i < size + 1)
	{
		*(char *)(j + i) = 0;
		i++;
	}
	return (j);
}
