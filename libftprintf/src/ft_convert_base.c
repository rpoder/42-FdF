/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:33:55 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/07 19:35:51 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_occ(int base_len, long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / base_len;
		count++;
	}
	return (count);
}

char	*convert_base(char *base, long nb)
{
	int		occ;
	size_t	base_len;
	char	*dst;

	if (nb < 0)
		nb = nb + UINT_MAX + 1;
	base_len = ft_strlen(base);
	occ = count_occ(base_len, nb);
	dst = (char *)malloc((occ + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	dst[occ] = '\0';
	occ--;
	if (nb == 0)
		dst[0] = '0';
	while (nb)
	{
		dst[occ] = base[nb % base_len];
		nb = nb / base_len;
		occ--;
	}
	return (dst);
}
