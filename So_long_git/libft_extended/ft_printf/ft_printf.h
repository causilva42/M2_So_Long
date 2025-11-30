/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:05:55 by causilva          #+#    #+#             */
/*   Updated: 2025/09/22 11:54:42 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// ----------------------------------------------
// External Header
// Beware - ft_printf may use ext funcs:
// 	write, malloc, free
// 	va_start, va_arg, va_copy, va_end.
// ----------------------------------------------
int	ft_printf(const char *format, ...);

#endif