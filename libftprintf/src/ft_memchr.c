/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:16:05 by rpoder            #+#    #+#             */
/*   Updated: 2021/11/26 17:51:57 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*casted_s;
	char		casted_c;
	size_t		i;

	casted_s = (const char *)s;
	casted_c = (char)c;
	i = 0;
	while (i < n)
	{
		if (casted_s[i] == casted_c)
			return ((void *) &casted_s[i]);
		i++;
	}
	return (NULL);
}
