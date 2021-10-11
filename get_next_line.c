/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-alen <jde-alen@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:01:08 by jde-alen          #+#    #+#             */
/*   Updated: 2021/10/11 18:25:17 by jde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_break(char *buff)
{
	if (!buff)
		return (0);
	if (ft_srchr(buff, '\n'))
		return (1);
	else
	return (0);	
}
