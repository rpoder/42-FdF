/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srt_applyft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:37:12 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/07 19:37:36 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_applyfunction(char *s, int (*f)(int))
{
	int	i;

	if (!s)
		return (NULL);
	if (!f)
		return (s);
	i = 0;
	while (s[i])
	{
		s[i] = f(s[i]);
		i++;
	}
	return (s);
}
