/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_field_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:49:20 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/07 07:45:41 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_field_int(va_list args, t_percent *percent)
{
	long	nbr ;
	int		len ;
	int		written ;
	int		space ;

	nbr = va_arg(args, int) ;
	len = ft_intlen(nbr) ;
	written = len ;
	space = percent->field.min - (len * (len >= percent->field.max)
		+ percent->field.max * (len < percent->field.max)) ;
	while ((!percent->zero || percent->field.period) && !percent->minus
		&& space-- > (nbr < 0 || percent->plus || percent->blank))
		written += ft_write_field(percent) ;
	written += ft_write_sign(nbr, percent) ;
	while (percent->zero && !percent->minus
		&& space-- > (nbr < 0 || percent->plus || percent->blank))
		written += ft_write_field(percent) ;
	while (percent->field.max-- > len - (nbr < 0))
		written += write(STDOUT_FILENO, "0", 1) ;
	ft_putlongnbr_fd(ft_abs(nbr), STDOUT_FILENO) ;
	while (percent->minus
		&& space-- > (nbr < 0 || percent->plus || percent->blank))
		written += ft_write_field(percent) ;
	return (percent->format = 0, written) ; //FIXME: how ?
}


int ft_field_uint(va_list args, t_percent *percent)
{
	unsigned int	nbr ;
	int		len ;
	int		written ;
	int		space ;
	nbr = va_arg(args, unsigned int) ;
	len = ft_uintlen(nbr) ;
	written = len ;
	space = percent->field.min - (len * (len >= percent->field.max)
		+ percent->field.max * (len < percent->field.max)) ;
	while ((!percent->zero || percent->field.period)
		&& !percent->minus && space-- > 0)
		written += ft_write_field(percent) ;
	while (percent->zero && !percent->minus && space-- > 0)
		written += ft_write_field(percent) ;
	while (percent->field.max-- > len)
		written += write(STDOUT_FILENO, "0", 1) ;
	ft_putunbr_fd(nbr, STDOUT_FILENO) ;
	while (percent->minus && space-- > 0)
		written += ft_write_field(percent) ;
	return (percent->format = 0, written) ;
}

int ft_field_hex(va_list args, t_percent *percent)
{
	unsigned int	nbr ;
	int		len ;
	int		written ;
	int		space ;

	nbr = va_arg(args, unsigned int) ;
	len = ft_hexlen(nbr) ;
	written = len ;
	space = percent->field.min - (len * (len >= percent->field.max)
		+ percent->field.max * (len < percent->field.max)) ;
	while ((!percent->zero || percent->field.period)
		&& !percent->minus && space-- > (2 * (percent->hashtag)))
		written += ft_write_field(percent) ;
	written += ft_write_0x(percent) ;
	while (percent->zero && !percent->minus
		&& space-- > (2 * (percent->hashtag)))
		written += ft_write_field(percent) ;
	while (percent->field.max-- > len - (nbr < 0))
		written += write(STDOUT_FILENO, "0", 1) ;
	ft_puthexnbr_fd((unsigned long) nbr, STDOUT_FILENO, percent->format) ;
	while (percent->minus && space-- > (2 * (percent->hashtag)))
		written += ft_write_field(percent) ;
	return (percent->format = 0, written) ;
}

int ft_field_address(va_list args, t_percent *percent)
{
	unsigned long	nbr ;
	int		len ;
	int		written ;
	int		space ;

	nbr = va_arg(args, unsigned long) ;
	len = 5 ;
	if (nbr)
		len = ft_hexlen(nbr) ;
	written = len ;
	space = percent->field.min - len ;
	while ((!percent->zero || percent->field.period)
		&& !percent->minus && space-- > (2 * !!nbr))
		written += ft_write_field(percent) ;
	if (nbr)
		written += ft_write_0x(percent) ;
	while (percent->zero && !percent->minus && space-- > (2 * !!nbr))
		written += ft_write_field(percent) ;
	if (nbr)
		ft_puthexnbr_fd(nbr, STDOUT_FILENO, MIN) ;
	else
		write(STDOUT_FILENO, "(nil)", 5) ;
	while (percent->minus && space-- > (2 * !!nbr))
		written += ft_write_field(percent) ;
	return (percent->format = 0, written) ;
}
