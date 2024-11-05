/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_identifier_address.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:46:05 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/05 06:43:07 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_id_p(va_list args)
{
	unsigned long	nb ;

	nb = va_arg(args, unsigned long) ;
	write(STDERR_FILENO, "0x", 2) ;
	ft_puthexnbr_fd(nb, STDIN_FILENO, MIN) ;
	return (ft_hexlen(nb) + 2) ;
}
