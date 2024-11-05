/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_field_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:33:43 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/05 09:50:48 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_field_with_char (va_list args, t_percent *percent)
{
	int		written ;
	char	c ;

	written = 0 ;
	c = (char) va_arg(args, int) ;
	if (percent->minus)
		written += write(STDIN_FILENO, &c, 1) ;
	while (percent->field.min-- > 1)
		written += write(STDIN_FILENO, " ", 1) ;
	if (!percent->minus)
		written += write(STDIN_FILENO, &c, 1) ;
	percent->format = 0 ;
	return written ;
}

/* doubling space part, not representative of how it is imo */
// int ft_field_with_str(va_list args, t_percent *percent)
// {
// 	char	*str ;
// 	int		len ;
// 	int		written ;

// 	str = va_arg(args, char *) ;
// 	len = ft_strlen(str) ;
// 	if (percent->field.max < len && percent->field.period)
// 		len = percent->field.max ;
// 	written = 0 ;
// 	if (!percent->minus)
// 		while (percent->field.min-- > len)
// 			written += write(STDIN_FILENO, " ", 1) ;
// 	if (percent->field.max < len && percent->field.period)
// 		if (percent->field.max < len && percent->field.period)
// 			while(percent->field.max-- > 0)
// 				written += write(STDIN_FILENO, str++, 1) ;
// 		else
// 			written += write(STDIN_FILENO, str, len) ;
// 	else
// 		written += write(STDIN_FILENO, str, len) ;
// 	if (percent->minus)
// 		while (percent->field.min-- > len)
// 			written += write(STDIN_FILENO, " ", 1) ;
// 	percent->format = 0 ;
// 	return (written) ;
// }


int ft_putstr_max_field_width(t_percent *percent, char **str, int len)
{
	int written ;

	written = 0 ;
	if (percent->field.max < len && percent->field.period)
		while(percent->field.max-- > 0)
			written += write(STDIN_FILENO, (*str)++, 1) ;
	else
		written += write(STDIN_FILENO, *str, len) ;
	return written ;
}

int ft_field_with_str(va_list args, t_percent *percent)
{
	char	*str ;
	int		len ;
	int		written ;

	str = va_arg(args, char *) ;
	len = ft_strlen(str) ;
	if (percent->field.max < len && percent->field.period)
		len = percent->field.max ;
	written = 0 ;
	if (percent->minus)
		written += ft_putstr_max_field_width(percent, &str, len) ;
	while (percent->field.min-- > len)
		written += write(STDIN_FILENO, " ", 1) ;
	if (!percent->minus)
		written += ft_putstr_max_field_width(percent, &str, len) ;
	percent->format = 0 ;
	return (written) ;
}
