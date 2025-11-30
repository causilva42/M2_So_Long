/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:05:55 by causilva          #+#    #+#             */
/*   Updated: 2025/08/28 12:19:50 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// ----------------------------------------------
// External Header
// Beware - get_next_line may use ext funcs:
// 	read, malloc, free.
// ----------------------------------------------
char	*get_next_line(int fd);

#endif