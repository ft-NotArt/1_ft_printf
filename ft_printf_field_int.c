/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_field_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:49:20 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/09 09:14:21 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_set_space(t_percent *percent, int len)
{
	int space ;

	space = percent->field.min - (len * (len >= percent->field.max)
		+ percent->field.max * (len < percent->field.max)) ;
	return space ;
}

static int ft_field_zero(t_percent *percent, int nbr) //FIXME: too tired to think about anything
{
	int		written ;
	int		space ;
	int		len ;

	len = ft_intlen(nbr) ;
	space = ft_set_space(percent, len) - (percent->plus || percent->blank)
		+ (percent->field.period && percent->field.max == 0) ;
	written = 0 ;
	// printf("\n\tmin : %d, max : %d, len : %d, space : %d\n", percent->field.min, percent->field.max, len, space) ;
	while ((!percent->zero || percent->field.period)
		&& !percent->minus && space-- > 0)
		written += ft_write_field(percent) ;
	written += ft_write_sign(0, percent) ;
	while (percent->zero && !percent->minus && space-- > 0)
		written += ft_write_field(percent) ;
	while (percent->field.max-- > 0)
		written += write(STDOUT_FILENO, "0", 1) ;
	if (!percent->field.period)
		written += write(STDOUT_FILENO, "0", 1) ;
	else if (space-- > 0)
		written += ft_write_field(percent) ;
	// printf("ici space : %d\n", space) ;
	while (percent->minus && space-- > 0)
		written += ft_write_field(percent) ;
	return (percent->format = 0, written) ;
}

int ft_field_int(va_list args, t_percent *percent)
{
	int		nbr ;
	int		len ;
	int		written ;
	int		space ;

	nbr = va_arg(args, int) ;
	if (nbr == 0)
		return ft_field_zero(percent, nbr) ;
	len = ft_intlen(nbr) ;
	written = len ;
	space = ft_set_space(percent, len) - (((percent->plus || percent->blank)
		&& nbr >= 0) || (len <= percent->field.max && nbr < 0)) ;
	while ((!percent->zero || percent->field.period)
		&& !percent->minus && space-- > 0)
		written += ft_write_field(percent) ;
	written += ft_write_sign(nbr, percent) ;
	while (percent->zero && !percent->minus && space-- > 0)
		written += ft_write_field(percent) ;
	while (percent->field.max-- > len - (nbr < 0))
		written += write(STDOUT_FILENO, "0", 1) ;
	ft_putlongnbr_fd(ft_abs(nbr), STDOUT_FILENO) ;
	while (percent->minus && space-- > 0)
		written += ft_write_field(percent) ;
	return (percent->format = 0, written) ;
}

// {

// 	while ((!percent->zero || percent->field.period) && !percent->minus
// 		&& space-- > (nbr < 0 || percent->plus || percent->blank))
// 		written += ft_write_field(percent) ;
// 	written += ft_write_sign(nbr, percent) ;
// 	while (percent->zero && !percent->minus
// 		&& space-- > (nbr < 0 || percent->plus || percent->blank))
// 		written += ft_write_field(percent) ;
// 	while (percent->field.max-- > len - (nbr < 0))
// 		written += write(STDOUT_FILENO, "0", 1) ;
// 	ft_putlongnbr_fd(ft_abs(nbr), STDOUT_FILENO) ;
// 	while (percent->minus
// 		&& space-- > (nbr < 0 || percent->plus || percent->blank))
// 		written += ft_write_field(percent) ;
// 	return (percent->format = 0, written) ; //FIXME: how ?
// }

int ft_field_uint(va_list args, t_percent *percent)
{
	unsigned int	nbr ;
	int		len ;
	int		written ;
	int		space ;
	nbr = va_arg(args, unsigned int) ;
	if (nbr == 0)
		return ft_field_zero(percent, nbr) ;
	len = ft_uintlen(nbr) ;
	written = len ;
	space = ft_set_space(percent, len) ;
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
	if (nbr == 0)
		return ft_field_zero(percent, nbr) ;
	len = ft_hexlen(nbr) ;
	written = len ;
	space = ft_set_space(percent, len) - (2 * (percent->hashtag && nbr != 0)) ;
		// - 2 * (nbr == 0 && percent->field.period)
	while ((!percent->zero || percent->field.period)
		&& !percent->minus && space-- > 0) // (2 * (percent->hashtag))
		written += ft_write_field(percent) ;
	if (nbr != 0)
		written += ft_write_0x(percent) ;
	while (percent->zero && !percent->minus
		&& space-- > 0) // (2 * (percent->hashtag))
		written += ft_write_field(percent) ;
	while (percent->field.max-- > len - (nbr < 0))
		written += write(STDOUT_FILENO, "0", 1) ;
	ft_puthexnbr_fd((unsigned long) nbr, STDOUT_FILENO, percent->format) ;
	while (percent->minus && space-- > 0) // (2 * (percent->hashtag))
		written += ft_write_field(percent) ;
	return (percent->format = 0, written) ;
}
