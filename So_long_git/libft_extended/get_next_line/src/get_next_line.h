/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:13:59 by causilva          #+#    #+#             */
/*   Updated: 2025/09/22 16:48:01 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_dynstr
{
	char	*string;
	int		len;
	int		size;
}	t_dynstr;

//----------------------------------------------
//----------------GET_NEXT_LINE.C---------------
//----------------------------------------------
char	*get_next_line(int fd);
void	update_string(t_dynstr *line, const char *buffer);
int		update_buffer(char *buffer);

#endif