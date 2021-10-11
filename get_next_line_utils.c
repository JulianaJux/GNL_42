/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-alen <jde-alen@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:01:00 by jde-alen          #+#    #+#             */
/*   Updated: 2021/10/11 18:28:30 by jde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

