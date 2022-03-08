/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:39:10 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/03 17:53:39 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, char const *set)
{
	char	*dst;
	size_t	len_s1;

	if (!s1 || !set)
		return (NULL);
	while (ft_strrchr(set, *s1) && *s1 != '\0')
		s1++;
	len_s1 = ft_strlen(s1);
	while (ft_strrchr(set, s1[len_s1]) && len_s1 != 0)
		len_s1--;
	dst = ft_substr(s1, 0, len_s1 + 1);
	if (!dst)
		return (NULL);
	return (dst);
}
