/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-alen <jde-alen@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:01:11 by jde-alen          #+#    #+#             */
/*   Updated: 2021/10/17 20:58:47 by jde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*ft_strcat(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *str, size_t start, size_t len);
char	*ft_bzero(size_t size);

#endif