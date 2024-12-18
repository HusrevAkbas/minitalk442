/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:08:21 by huakbas           #+#    #+#             */
/*   Updated: 2024/11/29 14:47:00 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	Return value:

	1- Read line: correct behavior
	2- NULL: there is nothing else to read, or an error occurred
*/
char	*clear(char **total)
{
	free(*total);
	*total = NULL;
	return (NULL);
}

char	*get_nl(char **total)
{
	char	*newline;
	char	*result;

	newline = ft_strchr(*total, '\n');
	result = malloc((newline - *total + 2) * sizeof(char));
	if (!result)
		return (clear(total));
	result[newline - *total + 1] = 0;
	ft_memmove(result, *total, newline - *total + 1);
	ft_memmove(*total, newline + 1, ft_strlen(newline));
	return (result);
}

char	*read_file(char *total, char *buffer, int fd, int *bytes)
{
	char	*middle;

	while (total && !ft_strchr(total, '\n') && *bytes > 0)
	{
		*bytes = read(fd, buffer, BUFFER_SIZE);
		if (*bytes == -1)
			return (clear(&total));
		if (*bytes > 0)
		{
			buffer[*bytes] = 0;
			middle = total;
			total = ft_strnjoin(total, buffer, *bytes);
			free(middle);
			if (!total)
				return (clear(&total));
		}
		else if (*bytes == 0)
			return (total);
		else
			return (clear(&total));
	}
	return (total);
}

char	*set_line(char **total, char *buffer, int fd)
{
	char	*result;
	int		bytes;

	bytes = 1;
	*total = read_file(*total, buffer, fd, &bytes);
	if (!*total)
		return (clear(total));
	if (bytes == 0 && !(**total))
		return (clear(total));
	else if (**total && !ft_strchr(*total, '\n'))
	{
		result = malloc((ft_strlen(*total) + 1) * sizeof(char));
		if (!result)
			return (clear(total));
		result[ft_strlen(*total)] = 0;
		ft_memmove(result, *total, ft_strlen(*total));
		**total = 0;
		return (result);
	}
	else if (**total && ft_strchr(*total, '\n'))
		return (get_nl(total));
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*total;
	char		*result;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (clear(&total));
	if (!total)
	{
		total = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!total)
			return (NULL);
		total[0] = 0;
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (clear(&total));
	if (ft_strchr(total, '\n'))
		result = get_nl(&total);
	else
		result = set_line(&total, buffer, fd);
	free(buffer);
	return (result);
}
