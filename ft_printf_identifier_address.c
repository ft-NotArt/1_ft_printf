/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_identifier_address.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:46:05 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/07 07:00:37 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_id_p(va_list args)
{
	unsigned long	nb ;

	nb = va_arg(args, unsigned long) ;
	if (!nb)
	{
		write(STDOUT_FILENO, "(nil)", 5) ;
		return 5 ;
	}
	write(STDERR_FILENO, "0x", 2) ;
	ft_puthexnbr_fd(nb, STDOUT_FILENO, MIN) ;
	return (ft_hexlen(nb) + 2) ;
}
