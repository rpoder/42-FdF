/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:21:59 by rpoder            #+#    #+#             */
/*   Updated: 2021/11/29 20:30:53 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_occ(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i ++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	if (i == 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*dst;

	nb = n;
	i = count_occ(nb);
	dst = (char *)ft_calloc(i + 1, sizeof(char));
	if (!dst)
		return (NULL);
	dst[i] = '\0';
	i--;
	if (nb == 0)
		dst[0] = '0';
	if (nb < 0)
	{
		nb = -nb;
		dst[0] = '-';
	}
	while (nb > 0)
	{
		dst[i] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
	return (dst);
}
