/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:54:16 by rpoder            #+#    #+#             */
/*   Updated: 2021/11/29 16:58:07 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < dstsize && *dst)
	{
		i++;
		dst++;
	}
	if (i == dstsize)
		return (i + ft_strlen(src));
	while (src[j])
	{
		if (j < dstsize - i - 1)
		{
			*dst = src[j];
			dst++;
		}
		j++;
	}
	*dst = '\0';
	return (i + j);
}
