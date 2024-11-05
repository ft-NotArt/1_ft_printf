/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_identifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:58:21 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/05 11:54:13 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	(*g_identifiers[UCHAR_MAX + 1])(va_list args) = { //FIXME: correct every function, there's no need to stock return value
['c'] = ft_id_c, ['s'] = ft_id_s, ['p'] = ft_id_p,
['d'] = ft_id_d, ['i'] = ft_id_d, ['u'] = ft_id_u,
['x'] = ft_id_x, ['X'] = ft_id_X, ['%'] = ft_id_percent};


int ft_printf_flag_handling(va_list args, t_percent *percent)
{
	if (percent->hashtag)
		return (ft_flag_hashtag(args, percent)) ;
	if (percent->blank)
		return (ft_flag_blank(args, percent)) ;
	if (percent->plus)
		return (ft_flag_plus(args, percent)) ;
	return (0) ;
}
// (percent->field.min || percent->field.period)
/* minus flag will be handled by field part, it doesn't change shit whitout one*/
/* same shit with zero flag*/
/* - 0 . */
int ft_printf_field_handling(va_list args, t_percent *percent)
{
	if (percent->field.min || percent->field.period)
	{
		if (percent->format == 'c')
			return (ft_field_with_char(args, percent)) ;
		if (percent->format == 's')
			return (ft_field_with_str(args, percent)) ;
		if (percent->format == 'd'
			|| percent->format == 'i')
			return (ft_field_with_int(args, percent)) ;
		if (percent->format == 'u')
			return (ft_field_with_uint(args, percent)) ;
		if (percent->format == 'x'
			|| percent->format == 'X')
			return (ft_field_with_hex(args, percent)) ;
	}
	return 0 ;
}

int	ft_printf_format_handling(va_list args, t_percent *percent)
{
	if (!g_identifiers[percent->format])
		return (0);
	return (g_identifiers[percent->format](args));
}

int ft_format(va_list args, t_percent *percent)
{
	int written ;

	written = 0 ;
	written += ft_printf_flag_handling(args, percent) ;
	written += ft_printf_field_handling(args, percent) ;
	written += ft_printf_format_handling(args, percent) ;
	return (written) ;
}