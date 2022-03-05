/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:54:31 by rpoder            #+#    #+#             */
/*   Updated: 2021/12/17 17:39:13 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trim_rest(char *to_trim)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (to_trim[i] != '\n' && to_trim[i])
		i++;
	if (!to_trim[i])
	{
		free(to_trim);
		return (NULL);
	}
	tmp = malloc((ft_strlen(to_trim) - i + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i++;
	while (to_trim[i])
		tmp[j++] = to_trim[i++];
	tmp[j] = '\0';
	free(to_trim);
	return (tmp);
}

char	*ft_trim_line(char	*to_trim)
{
	char	*tmp;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (!to_trim[i])
		return (NULL);
	while (to_trim[len] != '\n' && to_trim[len])
		len++;
	if (to_trim[len] == '\n')
		len++;
	tmp = (char *)malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		tmp[i] = to_trim[i];
		i++;
	}
	tmp[len] = '\0';
	return (tmp);
}

char	*ft_read_line(int fd, char *reste)
{
	char	*buf;
	int		ret;

	ret = 1;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!ft_strchr(reste, '\n') && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		reste = ft_strjoin(reste, buf);
	}
	free(buf);
	return (reste);
}

char	*get_next_line(int fd)
{
	static char	*reste;
	char		*ligne;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	reste = ft_read_line(fd, reste);
	if (!reste)
		return (NULL);
	ligne = ft_trim_line(reste);
	reste = ft_trim_rest(reste);
	return (ligne);
}
