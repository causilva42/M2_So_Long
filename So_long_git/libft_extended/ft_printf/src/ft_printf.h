/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:36:23 by causilva          #+#    #+#             */
/*   Updated: 2025/09/22 16:47:09 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../../libft/libft.h"

# define BASE_DEC "0123456789"
# define BASE_LHEX "0123456789abcdef"
# define BASE_UHEX "0123456789ABCDEF"

typedef struct s_iocount
{
	int	read;
	int	printed;
}	t_iocount;

//----------------------------------------------
//-----------------FT_PRINTF.C------------------
//----------------------------------------------
int			ft_printf(const char *format, ...);
t_iocount	choose_print(char c, va_list *args);
t_iocount	print_pure(const char *s);

//----------------------------------------------
//-------------------PRINTS.C-------------------
//----------------------------------------------
int			print_c(unsigned char c);
int			print_s(const char *s);	
int			print_p(void *ptr);
int			print_li(long n);
int			print_lubase(unsigned long n, const char *base);

#endif