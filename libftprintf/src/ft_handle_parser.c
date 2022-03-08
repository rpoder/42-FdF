/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:47:50 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/07 22:10:01 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_handle_s(char *arg)
{
	size_t	value;

	value = 0;
	if (arg == NULL)
		value = ft_putstr_fd("(null)", 1);
	else
		value = ft_putstr_fd(arg, 1);
	return (value);
}

size_t	ft_handle_p(unsigned long arg)
{
	size_t	value;
	char	*tmp;

	tmp = convert_base_add("0123456789abcdef", arg);
	value = ft_putstr_fd(tmp, 1);
	free(tmp);
	return (value);
}

size_t	ft_handle_u(int arg)
{
	size_t		value;
	long int	tmp;
	int			b;

	b = arg;
	if (b < 0)
		tmp = b + UINT_MAX + 1;
	else
		tmp = b;
	value = ft_putnbr_fd(tmp, 1);
	return (value);
}

size_t	ft_handle_x(int arg)
{
	size_t	value;
	char	*tmp;

	tmp = convert_base("0123456789abcdef", arg);
	value = ft_putstr_fd(tmp, 1);
	free(tmp);
	return (value);
}

size_t	ft_handle_xbis(int arg)
{
	size_t	value;
	char	*tmp;

	tmp = convert_base("0123456789abcdef", arg);
	value = ft_putstr_fd(str_applyfunction((tmp), &ft_toupper), 1);
	free(tmp);
	return (value);
}
