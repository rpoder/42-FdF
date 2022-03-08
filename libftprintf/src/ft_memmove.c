/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:31:28 by rpoder            #+#    #+#             */
/*   Updated: 2021/11/26 19:56:44 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*casted_dst;
	const char	*casted_src;
	size_t		i;

	casted_src = (const char *)src;
	casted_dst = (char *)dst;
	if (!casted_dst && !casted_src)
		return (NULL);
	if (casted_dst > casted_src)
	{
		i = len - 1;
		while (i + 1 > 0)
		{
			casted_dst[i] = casted_src[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
