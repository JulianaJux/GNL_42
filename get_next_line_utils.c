/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-alen <jde-alen@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:19:52 by jde-alen          #+#    #+#             */
/*   Updated: 2021/10/24 15:12:18 by jde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	unsigned int	j;

	j = 0;
	while (*s != '\0')
	{
		j++;
		s++;
	}
	return (j);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	j;

	if (!src || !dst)
		return (0);
	srcsize = ft_strlen(src);
	j = 0;
	if (dstsize != 0)
	{
		while ((src[j] != '\0') && (j < (dstsize - 1)))
		{
			dst[j] = src[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (srcsize);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			j;
	unsigned char	*d;
	unsigned char	*s;

	j = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (j < n)
	{
		d[j] = s[j];
		j++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*ostr;

	if (s1 == 0 || s2 == 0)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ostr = str + ft_strlen(s1);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(ostr, s2, ft_strlen(s2));
	str[ft_strlen(s1) + ft_strlen(s2)] = 0;
	return (str);
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
