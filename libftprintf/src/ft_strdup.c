/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:59:27 by rpoder            #+#    #+#             */
/*   Updated: 2021/11/28 17:41:18 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		s_len;
	int		i;
	char	*ptr;

	i = 0;
	s_len = ft_strlen(s);
	ptr = (char *)ft_calloc(s_len + 1, sizeof(char));
	if (ptr == 0)
		return (NULL);
	ft_memmove(ptr, s, s_len);
	ptr[s_len] = '\0';
	return (ptr);
}
