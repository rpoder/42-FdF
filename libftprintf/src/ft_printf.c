/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:47:37 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/08 17:05:06 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_parse(char c, va_list args)
{
	size_t	value;

	value = 0;
	if (c == 'c')
		value = ft_putchar_fd(va_arg(args, int), 1);
	if (c == 's')
		value = ft_handle_s(va_arg(args, char *));
	if (c == 'p')
		value = ft_handle_p(va_arg(args, unsigned long));
	if (c == 'd' || c == 'i')
		value = ft_putnbr_fd(va_arg(args, int), 1);
	if (c == 'u')
		value = ft_handle_u(va_arg(args, int));
	if (c == 'x')
		value = ft_handle_x(va_arg(args, int));
	if (c == 'X')
		value = ft_handle_xbis(va_arg(args, int));
	if (c == '%')
		value = ft_putchar_fd('%', 1);
	return (value);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	value;
	size_t	i;

	va_start(args, str);
	i = 0;
	value = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_strrchr("csdpiuxX%", str[i + 1]) && str[i + 1])
		{
			value += ft_parse(str[i + 1], args);
			i += 2;
		}
		else if (str[i] == '%' && !(ft_strrchr("csdpiuxX", str[i + 1])))
			i = i + 2;
		else if (str[i] != '%' && str[i])
		{
			value += ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	va_end(args);
	return (value);
}
