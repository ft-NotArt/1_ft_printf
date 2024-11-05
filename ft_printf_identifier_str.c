/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_identifier_str.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:17:49 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/05 03:27:35 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_id_c(va_list args)
{
	char c ;

	c = (char) va_arg(args, int) ;
	write(STDIN_FILENO, &c, 1) ;
	return 1 ;
}

int ft_id_s(va_list args)
{
	char *str ;
	int len ;

	str = va_arg(args, char *) ;
	len = ft_strlen(str) ;
	write(STDIN_FILENO, str, len) ;
	return len ;
}

int ft_id_percent()
{
	write(STDIN_FILENO, "%", 1) ;
	return 1 ;
}
