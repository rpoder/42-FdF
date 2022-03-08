/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:24:10 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/07 21:35:58 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_occ_add(int base_len, unsigned long nb)
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

char	*convert_base_add(char *base, unsigned long nb)
{
	int		occ;
	size_t	base_len;
	char	*dst;

	base_len = ft_strlen(base);
	occ = count_occ_add(base_len, nb);
	dst = (char *)malloc((occ + 1 + 2) * sizeof(char));
	if (!dst)
		return (NULL);
	dst[0] = '0';
	dst[1] = 'x';
	occ += 2;
	dst[occ] = '\0';
	occ--;
	if (nb == 0)
		dst[2] = '0';
	while (nb)
	{
		dst[occ] = base[nb % base_len];
		nb = nb / base_len;
		occ--;
	}
	return (dst);
}
