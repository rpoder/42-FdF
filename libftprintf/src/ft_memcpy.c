/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:43:21 by rpoder            #+#    #+#             */
/*   Updated: 2021/11/26 15:28:09 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*casted_dst;
	const char	*casted_src;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	casted_dst = (char *)dst;
	casted_src = (const char *)src;
	i = 0;
	while (i < n)
	{
		casted_dst[i] = casted_src[i];
		i ++;
	}
	return (dst);
}
