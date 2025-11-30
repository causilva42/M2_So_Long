/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: causilva <@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:35:48 by causilva          #+#    #+#             */
/*   Updated: 2025/05/22 15:31:53 by causilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(unsigned char c)
{
	return (write(1, &c, 1));
}

int	print_s(const char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	print_p(void *ptr)
{
	int	write_return[2];

	if (!ptr)
		return (write(1, "(nil)", 5));
	write_return[0] = write(1, "0x", 2);
	if (write_return[0] < 0)
		return (write_return[0]);
	write_return[1] = print_lubase((unsigned long ) ptr, BASE_LHEX);
	if (write_return[1] < 0)
		return (write_return[1]);
	return (write_return[0] + write_return[1]);
}

int	print_li(long n)
{
	int	write_return[2];

	if (n < 0)
	{
		write_return[0] = write(1, "-", 1);
		if (write_return[0] < 0)
			return (write_return[0]);
		write_return[1] = print_lubase(-n, BASE_DEC);
	}
	else
	{
		write_return[0] = 0;
		write_return[1] = print_lubase(n, BASE_DEC);
	}
	if (write_return[1] < 0)
		return (write_return[1]);
	return (write_return[0] + write_return[1]);
}

int	print_lubase(unsigned long n, const char *base)
{
	int	base_len;
	int	write_return[2];

	base_len = ft_strlen(base);
	if (n < (unsigned long) base_len)
		return (write(1, &base[n], 1));
	write_return[0] = print_lubase(n / base_len, base);
	if (write_return[0] < 0)
		return (write_return[0]);
	write_return[1] = print_lubase(n % base_len, base);
	if (write_return[1] < 0)
		return (write_return[1]);
	return (write_return[0] + write_return[1]);
}
