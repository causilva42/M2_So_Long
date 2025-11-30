/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:13:44 by causilva          #+#    #+#             */
/*   Updated: 2025/05/20 11:59:56 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	t_dynstr	line;
	int			read_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (t_dynstr){NULL, 0, 1};
	read_return = 1;
	while (read_return != 0)
	{
		if (buffer[0] == '\0')
		{
			read_return = read(fd, buffer, BUFFER_SIZE);
			if (read_return < 0)
				return (free(line.string), NULL);
			buffer[read_return] = '\0';
		}
		update_string(&line, buffer);
		if (!line.string)
			return (NULL);
		read_return *= update_buffer(buffer);
	}
	if (line.string[0] == '\0')
		return (free(line.string), NULL);
	return (line.string);
}

void	update_string(t_dynstr *line, const char *buffer)
{
	char	*new_string;
	int		b_len;

	b_len = 0;
	while (buffer[b_len] != '\0' && buffer[b_len] != '\n')
		b_len++;
	b_len += (buffer[b_len] == '\n');
	if (!line->string || (line->len + b_len + 1 > line->size))
	{
		while (line->len + b_len + 1 > line->size)
			line->size *= 2;
		new_string = malloc(line->size * sizeof(char));
		if (!new_string)
		{
			free(line->string);
			line->string = NULL;
			return ;
		}
		if (line->string)
			ft_strlcpy(new_string, line->string, line->len + 1);
		free(line->string);
		line->string = new_string;
	}
	line->len += ft_strlcpy(&(line->string)[line->len], buffer, b_len + 1);
}

int	update_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			i++;
			ft_strlcpy(buffer, &buffer[i], BUFFER_SIZE + 1 - i);
			return (0);
		}
		i++;
	}
	buffer[0] = '\0';
	return (1);
}
