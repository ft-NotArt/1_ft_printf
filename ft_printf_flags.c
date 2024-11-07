/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:42:29 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/07 01:24:29 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_flag_hashtag(va_list args, t_percent *percent)
{
	va_list			cpy ;
	unsigned int	address ;
	int				written ;

	va_copy(cpy, args) ;
	address = va_arg(cpy, unsigned int) ;
	written = 0 ;
	if (percent->format == 'x' && address != 0)
		written = write(STDOUT_FILENO, "0x", 2) ;
	if (percent->format == 'X' && address != 0)
		written = write(STDOUT_FILENO, "0X", 2) ;
	va_end(cpy) ;
	return (written);
}

int ft_flag_blank(va_list args, t_percent *percent)
{
	va_list cpy ;
	int		val ;
	int		written ;

	va_copy(cpy, args) ;
	val = va_arg(cpy, int) ;
	written = 0 ;
	if ((percent->format == 'd' || percent->format == 'i')
		&& val >= 0)
		written = write(STDOUT_FILENO, " ", 1) ;
	va_end(cpy) ;
	return (written);
}

int ft_flag_plus(va_list args, t_percent *percent)
{
	va_list cpy ;
	int		val ;
	int		written ;

	va_copy(cpy, args) ;
	val = va_arg(cpy, int) ;
	written = 0 ;
	if ((percent->format == 'd' || percent->format == 'i')
		&& val >= 0)
		written = write(STDOUT_FILENO, "+", 1) ;
	va_end(cpy) ;
	return (written);
}
