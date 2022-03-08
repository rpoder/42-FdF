/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:19:38 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/03 13:47:36 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	if (s_len <= start)
		len = 0;
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == 0)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
