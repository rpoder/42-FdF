/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:31:02 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/04 18:21:01 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	unsigned long	res;
	int				neg;
	int				i;

	res = 0;
	neg = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		res = res * 10 + ((unsigned long) s[i] - 48);
		i++;
	}
	if (res > 2147483647 && neg == 1)
		return (-1);
	if (res > 2147483648 && neg == -1)
		return (0);
	return ((int)(res * neg));
}
