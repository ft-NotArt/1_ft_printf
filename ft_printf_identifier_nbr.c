/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_identifier_nbr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:41:52 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/07 01:24:29 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_id_d(va_list args)
{
	int	nb ;

	nb = va_arg(args, int) ;
	ft_putnbr_fd(nb, STDOUT_FILENO) ;
	return ft_intlen(nb) ;
}

int ft_id_u(va_list args)
{
	unsigned int	nb ;

	nb = va_arg(args, unsigned int) ;
	ft_putunbr_fd(nb, STDOUT_FILENO) ;
	return ft_uintlen(nb) ;
}

int ft_id_x(va_list args)
{
	unsigned int	nb ;

	nb = va_arg(args, unsigned int) ;
	ft_puthexnbr_fd((unsigned long) nb, STDOUT_FILENO, MIN) ;
	return ft_hexlen(nb) ;
}

int ft_id_X(va_list args)
{
	unsigned int	nb ;

	nb = va_arg(args, unsigned int) ;
	ft_puthexnbr_fd((unsigned long) nb, STDOUT_FILENO, MAJ) ;
	return ft_hexlen(nb) ;
}
