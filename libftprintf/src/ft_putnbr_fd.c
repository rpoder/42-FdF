/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:59:30 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/07 21:33:49 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(long int n, int fd)
{
	unsigned int	nb;
	size_t			value;

	value = 0;
	if (n < 0)
	{
		value += ft_putchar_fd('-', fd);
		nb = -n;
	}
	else
		nb = n;
	if (nb > 9)
	{
		value += ft_putnbr_fd(nb / 10, fd);
		nb = nb % 10;
	}
	value += ft_putchar_fd(nb + '0', fd);
	return (value);
}
