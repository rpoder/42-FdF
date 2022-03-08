/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:09:25 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/03 14:06:22 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystak, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	if (!needle[0])
		return ((char *)haystak);
	while (haystak[i] && i < len)
	{
		if (haystak[i] == needle[0])
		{
			j = 0;
			while (haystak[i + j] == needle[j] && haystak[i + j]
				&& needle[j] && i + j < len)
				j++;
			if (needle[j] == '\0')
				return ((char *) haystak + i);
		}
		i++;
	}
	return (NULL);
}
