/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtresa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:29:48 by gtresa            #+#    #+#             */
/*   Updated: 2021/02/25 15:30:56 by gtresa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_rem(char **rem, char **line, char *buf)
{
	int	i;

	i = 0;
	if (ft_strchr_gnl(*rem, '\n'))
	{
		while ((*rem)[i] != '\n')
			i++;
		(*rem)[i] = '\0';
		*line = ft_strdup(*rem);
		if (!line)
			return (-1);
		i = ft_strcpy(*rem, &(*rem)[i + 1]);
		free(buf);
		return (1);
	}
	return (0);
}

static int	read_stream(int fd, char **line, char *buf, char **rem)
{
	int	byte;

	if (!(ft_strchr_gnl(*rem, '\n')))
	{
		byte = read(fd, buf, BUFFER_SIZE);
		while (byte)
		{
			if (byte == -1)
				return (byte);
			buf[byte] = '\0';
			*rem = ft_strjoin_gnl(*rem, buf);
			if (!(*rem))
				return (-1);
			if (check_rem(&(*rem), line, buf))
				return (1);
			byte = read(fd, buf, BUFFER_SIZE);
		}
	}
	else if (check_rem(&(*rem), line, buf))
		return (1);
	*line = ft_strdup(*rem);
	if (!(*line))
		return (-1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			res;
	static char	*rem;

	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	if (rem == NULL)
	{
		rem = ft_strdup("");
		if (!rem)
			return (-1);
	}
	res = read_stream(fd, line, buf, &rem);
	if (res < 1)
	{
		free(buf);
		my_free(rem);
	}
	return (res);
}
