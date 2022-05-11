/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:55:23 by rpoder            #+#    #+#             */
/*   Updated: 2022/02/14 18:41:50 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <assert.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define UINT_MAX 4294967295

char	*convert_base_add(char *base, unsigned long nb);
int		ft_printf(const char *str, ...);

size_t	ft_handle_s(char *arg);
size_t	ft_handle_p(unsigned long arg);
size_t	ft_handle_u(int arg);
size_t	ft_handle_x(int arg);
size_t	ft_handle_xbis(int arg);

size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
size_t	ft_putnbr_fd(long int n, int fd);
int		ft_toupper(int c);
char	*ft_strrchr(const char *s, int c);
char	*convert_base(char *base, long nb);
char	*str_applyfunction(char *s, int (*f)(int));

#endif
