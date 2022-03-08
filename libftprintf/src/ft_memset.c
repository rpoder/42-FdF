/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:22:03 by rpoder            #+#    #+#             */
/*   Updated: 2021/11/25 23:27:15 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*casted_s;

	casted_s = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		casted_s[i] = (char) c;
		i++;
	}
	return (s);
}
