/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:36:46 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/07 19:21:42 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putendl_fd(char *s, int fd)
{
	int		s_len;
	size_t	value;

	value = 0;
	if (s)
	{
		s_len = ft_strlen(s);
		value += write(fd, s, s_len);
		value += ft_putchar_fd('\n', fd);
	}
	return (value);
}
