/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_field_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:49:20 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/05 12:28:04 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_field_with_int(va_list args, t_percent *percent)
{
	int	nbr ;
	int	written ;
	int	len ;

	nbr = va_arg(args, int) ;
	len = ft_intlen(nbr) ;
	written = len ;
	while(percent->field.max-- > len)
		written += write(STDIN_FILENO, "0", 1) ;
	if(!percent->minus)
		while(percent->field.min > len++)
			written += write(STDIN_FILENO, " ", 1) ;
	ft_putnbr_fd(nbr, STDIN_FILENO) ;
	if(percent->minus)
		while(percent->field.min > len++)
			written += write(STDIN_FILENO, " ", 1) ;
	percent->format = 0 ;
	return written ;
}

int ft_field_with_uint (va_list args, t_percent *percent)
{
	unsigned int	nbr ;
	int	written ;
	int	len ;

	nbr = va_arg(args, unsigned int) ;
	len = ft_uintlen(nbr) ;
	written = len ;
	while(percent->field.max-- > len)
		written += write(STDIN_FILENO, "0", 1) ;
	if(!percent->minus)
		while(percent->field.min > len++)
			written += write(STDIN_FILENO, " ", 1) ;
	ft_putunbr_fd(nbr, STDIN_FILENO) ;
	if(percent->minus)
		while(percent->field.min > len++)
			written += write(STDIN_FILENO, " ", 1) ;
	percent->format = 0 ;
	return written ;
}
#include <stdio.h> //TODO: clc lahuiss
int ft_field_with_hex(va_list args, t_percent *percent)
{
	unsigned long	nbr ;
	int	written ;
	int	len ;

	nbr = va_arg(args, unsigned long) ;
	len = ft_hexlen(nbr) ;
	printf("\n\t\t\thexlen = ? %d", len) ;
	written = len ;
	while(percent->field.max-- > len)
		written += write(STDIN_FILENO, "0", 1) ;
	if(!percent->minus)
		while(percent->field.min > len++)
			written += write(STDIN_FILENO, " ", 1) ;
	if (percent->format == 'x')
		ft_puthexnbr_fd(nbr, STDIN_FILENO, MIN) ;
	else
		ft_puthexnbr_fd(nbr, STDIN_FILENO, MAJ) ;
	printf("\n\t\t\tbig written : %d", written) ;
	if(percent->minus)
		while(percent->field.min > len++) //FIXME: tf it print an extra space for ?
		{
			// printf("\n\tlen : %d, min : %d, nbr : %lu", len, percent->field.min, nbr) ;
			written += write(STDIN_FILENO, " ", 1) ;
		}
	percent->format = 0 ;
	return written ;
}
