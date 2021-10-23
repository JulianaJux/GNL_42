/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-alen <jde-alen@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:20:42 by jde-alen          #+#    #+#             */
/*   Updated: 2021/10/23 20:20:49 by jde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFFER_SIZE 

# include <unistd.h>
# include <stdlib.h>

/*get_next_line_protótipo*/
char	*get_next_line(int fd);

/*get_next_line_utils*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);


#endif