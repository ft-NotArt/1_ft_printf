/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:16:24 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/05 12:03:44 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> //TODO: clean this

int	ft_percent(char **format, va_list args)
{
	(*format)++;
	t_percent percent = ft_percent_init(format) ;
	return ft_format(args, &percent) ;
}

//__attribute__ ((format(printf, 1, 2)))
int	ft_printf(const char *format, ...) //TODO: Don't forget about the *
{
	char	*browseable_format ;
	va_list	args ;
	int		written ;

	va_start(args, format) ;
	browseable_format = (char *) format ;
	written = 0 ;
	while (*browseable_format != '\0')
	{
		if (*browseable_format == '%')
			written += ft_percent((&browseable_format), args) ;
		else
		{
			ft_putchar_fd(*browseable_format, STDOUT_FILENO) ;
			browseable_format++ ;
			written++ ;
		}
	}
	va_end(args) ;
	return written ;
}




// int main()
// {
// 	printf("\n%d\n", ft_printf("U%-0#5.9c\n\t%s\n\twU\n", '@', "c'est big")) ;
// 	printf("\n%d\n", ft_printf("!%d!\n", 5) - 3) ;
// }

#include <stdio.h>
int main ()
{
	int number ;
	// char *str ;
	// number = 5 ;
	// printf("| |%u| |\n", number) ;
	// printf("\n%d\n", ft_printf("!%u!\n", number) - 3) ;
	// number = -5 ;
	// printf("| |%u| |\n", number) ;
	// printf("\n%d\n", ft_printf("!%u!\n", number) - 3) ;
	// number = 0 ;
	// printf("| |%u| |\n", number) ;
	// printf("\n%d\n", ft_printf("!%u!\n", number) - 3) ;
	// number = INT_MAX ;
	// printf("| |%u| |\n", number) ;
	// printf("\n%d\n", ft_printf("!%u!\n", number) - 3) ;
	// number = INT_MIN ;
	// printf("| |%u| |\n", number) ;
	// printf("\n%d\n", ft_printf("!%u!\n", number) - 3) ;

	// printf("==================\n") ;
	// printf("==================\n") ;

	// number = 0 ;
    // printf("| |%x| |", number);
	// printf("return value : %d\n\n", ft_printf("!%x!\n", number) - 3) ;
	// number = 10 ;
    // printf("| |%x| |", number);
	// printf("return value : %d\n\n", ft_printf("!%x!\n", number) - 3) ;
	// number = 16 ;
    // printf("| |%x| |", number);
	// printf("return value : %d\n\n", ft_printf("!%x!\n", number) - 3) ;
	// number = INT_MAX ;
    // printf("| |%x| |", number);
	// printf("return value : %d\n\n", ft_printf("!%x!\n", number) - 3) ;
	// number = INT_MIN ;
    // printf("| |%x| |", number);
	// printf("return value : %d\n\n", ft_printf("!%x!\n", number) - 3) ;

	// printf("==================\n") ;
	// printf("==================\n") ;

    // printf("| |%p| |%p| |%p| |%p| |", (void *)0, NULL, str, &number);
    // printf("return value : %d\n\n", ft_printf("| |%p| |%p| |%p| |%p| |", (void *)0, NULL, str, &number)) ;
    // printf("return value : %d\n\n", ft_printf("| |%p| |", &number)) ;

	// printf("==================\n") ;
	// printf("++++++++++++++++++\n") ;
	// printf("==================\n") ;

	// number = 50 ;
	// printf("\treturn value : %d\n", printf("| |%d| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%+d| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%i| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%+i| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%d| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%+d| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%i| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%+i| |\n", number) - 7);
	// printf("==================\n") ;
	// number = -50 ;
	// printf("\treturn value : %d\n", printf("| |%d| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%+d| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%i| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%+i| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%d| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%+d| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%i| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%+i| |\n", number) - 7);
	// printf("==================\n") ;
	// number = 0 ;
	// printf("\treturn value : %d\n", printf("| |%d| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%+d| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%i| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%+i| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%d| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%+d| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%i| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%+i| |\n", number) - 7);

	// printf("==================\n") ;
	// printf("__________________\n") ;
	// printf("==================\n") ;

	// number = 50 ;
	// printf("\treturn value : %d\n", printf("| |%d| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |% d| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%i| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |% i| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%d| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |% d| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%i| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |% i| |\n", number) - 7);
	// printf("==================\n") ;
	// number = -50 ;
	// printf("\treturn value : %d\n", printf("| |%d| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |% d| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%i| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |% i| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%d| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |% d| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%i| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |% i| |\n", number) - 7);
	// printf("==================\n") ;
	// number = 0 ;
	// printf("\treturn value : %d\n", printf("| |%d| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |% d| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%i| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |% i| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%d| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |% d| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%i| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |% i| |\n", number) - 7);

	// printf("==================\n") ;
	// printf("##################\n") ;
	// printf("==================\n") ;

	// number = 50 ;
	// printf("\treturn value : %d\n", printf("| |%x| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%#x| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%X| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%#X| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%x| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%#x| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%X| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%#X| |\n", number) - 7);
	// printf("==================\n") ;
	// number = -50 ;
	// printf("\treturn value : %d\n", printf("| |%x| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%#x| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%X| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%#X| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%x| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%#x| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%X| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%#X| |\n", number) - 7);
	// printf("==================\n") ;
	// number = 0 ;
	// printf("\treturn value : %d\n", printf("| |%x| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%#x| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%X| |\n", number) - 7);
	// printf("\treturn value : %d\n", printf("| |%#X| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%x| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%#x| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%X| |\n", number) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%#X| |\n", number) - 7);

	printf("==================\n") ;
	printf(" SousPaddingOnADit\n") ;
	printf("==================\n") ;

	number = 12345 ;
	printf("\treturn value : %d\n", printf("| |%d| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3d| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.d| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%.3d| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.3d| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%8.3d| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.8d| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-8.3d| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.8d| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.9d| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.10d| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-5.8d| |\n", number) - 7);

	printf("------------------\n") ;

	printf("\treturn value : %d\n", ft_printf("| |%d| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3d| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.d| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%.3d| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.3d| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%8.3d| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.8d| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-8.3d| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.8d| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.9d| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.10d| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-5.8d| |\n", number) - 7);


	printf("==================\n") ;


	printf("\treturn value : %d\n", printf("| |%i| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3i| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.i| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%.3i| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.3i| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%8.3i| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.8i| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-8.3i| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.8i| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.9i| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.10i| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-5.8i| |\n", number) - 7);

	printf("------------------\n") ;

	printf("\treturn value : %d\n", ft_printf("| |%i| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3i| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.i| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%.3i| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.3i| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%8.3i| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.8i| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-8.3i| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.8i| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.9i| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.10i| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-5.8i| |\n", number) - 7);


	printf("==================\n") ;


	printf("\treturn value : %d\n", printf("| |%u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%8.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.8u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-8.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.8u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.9u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.10u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-5.8u| |\n", number) - 7);

	printf("------------------\n") ;

	printf("\treturn value : %d\n", ft_printf("| |%u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%8.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.8u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-8.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.8u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.9u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.10u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-5.8u| |\n", number) - 7);


	printf("=========-50=========\n") ;

	number = -50 ;
	printf("\treturn value : %d\n", printf("| |%u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%8.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.8u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-8.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.8u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.9u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.10u| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-5.8u| |\n", number) - 7);

	printf("------------------\n") ;

	printf("\treturn value : %d\n", ft_printf("| |%u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%8.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.8u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-8.3u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.8u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.9u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.10u| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-5.8u| |\n", number) - 7);


	printf("==================\n") ;

	number = 12345 ;
	printf("\treturn value : %d\n", printf("| |%x| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3x| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.x| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%.3x| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.3x| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%8.3x| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.8x| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-8.3x| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.8x| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.9x| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.10x| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-5.8x| |\n", number) - 7);

	printf("------------------\n") ;

	printf("\treturn value : %d\n", ft_printf("| |%x| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3x| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.x| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%.3x| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.3x| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%8.3x| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.8x| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-8.3x| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.8x| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.9x| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.10x| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-5.8x| |\n", number) - 7);


	printf("==================\n") ;


	printf("\treturn value : %d\n", printf("| |%X| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3X| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.X| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%.3X| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.3X| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%8.3X| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%3.8X| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-8.3X| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.8X| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.9X| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-3.10X| |\n", number) - 7);
	printf("\treturn value : %d\n", printf("| |%-5.8X| |\n", number) - 7);

	printf("------------------\n") ;

	printf("\treturn value : %d\n", ft_printf("| |%X| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3X| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.X| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%.3X| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.3X| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%8.3X| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%3.8X| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-8.3X| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.8X| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.9X| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-3.10X| |\n", number) - 7);
	printf("\treturn value : %d\n", ft_printf("| |%-5.8X| |\n", number) - 7);


	printf("==================\n") ;

	// printf("==================\n") ;
	// printf("  SurPaddingOnADit\n") ;
	// printf("==================\n") ;

	// str = "12345" ;
	// printf("\treturn value : %d\n", printf("| |%s| |\n", str) - 7);
	// printf("\treturn value : %d\n", printf("| |%3s| |\n", str) - 7);
	// printf("\treturn value : %d\n", printf("| |%3.s| |\n", str) - 7);
	// printf("\treturn value : %d\n", printf("| |%.3s| |\n", str) - 7);
	// printf("\treturn value : %d\n", printf("| |%3.3s| |\n", str) - 7);
	// printf("\treturn value : %d\n", printf("| |%8.3s| |\n", str) - 7);
	// printf("\treturn value : %d\n", printf("| |%3.8s| |\n", str) - 7);
	// printf("\treturn value : %d\n", printf("| |%-8.3s| |\n", str) - 7);
	// printf("\treturn value : %d\n", printf("| |%-3.8s| |\n", str) - 7);
	// printf("------------------\n") ;
	// printf("\treturn value : %d\n", ft_printf("| |%s| |\n", str) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%3s| |\n", str) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%3.s| |\n", str) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%.3s| |\n", str) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%3.3s| |\n", str) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%8.3s| |\n", str) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%3.8s| |\n", str) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%-8.3s| |\n", str) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%-3.8s| |\n", str) - 7);

	// printf("==================\n") ;
	// printf(" MiniPaddingOnADit\n") ;
	// printf("==================\n") ;

	// char c = '1' ;
	// printf("\treturn value : %d\n", printf("| |%c| |\n", c) - 7);
	// printf("\treturn value : %d\n", printf("| |%3c| |\n", c) - 7);
	// printf("\treturn value : %d\n", printf("| |%3.c| |\n", c) - 7);
	// printf("\treturn value : %d\n", printf("| |%-3.c| |\n", c) - 7);
	// printf("------------------\n") ;
	// printf("\treturn value : %d\n", ft_printf("| |%c| |\n", c) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%3c| |\n", c) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%3.c| |\n", c) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%-3.c| |\n", c) - 7);
	// printf("------------------\n") ;
	// printf("\treturn value : %d\n", printf("| |%-c| |\n", c) - 7);
	// printf("\treturn value : %d\n", printf("| |%-3c| |\n", c) - 7);
	// printf("\treturn value : %d\n", printf("| |%-3.c| |\n", c) - 7);
	// printf("\treturn value : %d\n", printf("| |%--3.c| |\n", c) - 7);
	// printf("------------------\n") ;
	// printf("\treturn value : %d\n", ft_printf("| |%-c| |\n", c) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%-3c| |\n", c) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%-3.c| |\n", c) - 7);
	// printf("\treturn value : %d\n", ft_printf("| |%--3.c| |\n", c) - 7);
}