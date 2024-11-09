/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:16:24 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/09 11:15:16 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h> //TODO: clean this

int	ft_percent(char **format, va_list args)
{
	(*format)++;
	t_percent percent = ft_percent_init(format, args) ;
	return ft_printf_format(args, &percent) ;
}

__attribute__ ((format(printf, 1, 2))) int	ft_printf(const char *format, ...) //TODO: Don't forget about the *
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





// #include <stdio.h>
// int main ()
// {
// // int number ;
// // // 	char *str ;


// // // 	printf("==================\n") ;
// // // 	printf(" SousPaddingOnADit\n") ;
// // // 	printf("==================\n") ;

// 	// printf("\treturn value : %d\n", printf("| %012d |", INT_MIN) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("| %012d |", INT_MIN) - 2);
// 	// printf("\treturn value : %d\n", printf("| %013i |", UINT_MAX) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("| %013i |", UINT_MAX) - 2);
// 	// printf("\treturn value : %d\n", printf("| %01u |", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("| %01u |", 0) - 2);


// 	// printf("------------------\n") ;
// 	// printf("------------------\n") ;





// 	// printf("\treturn value : %d\n", printf("|%5.0i|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%5.0i|", 0) - 2);

// 	// printf("\treturn value : %d\n", printf("|%5.i|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%5.i|", 0) - 2);

// 	// printf("\treturn value : %d\n", printf("|%-5.0i|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.0i|", 0) - 2);

// 	// printf("\treturn value : %d\n", printf("|%-5.i|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.i|", 0) - 2);

// 	// printf("\treturn value : %d\n", printf("|% 41.24d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|% 41.24d|", 0) - 2);

// 	// printf("\treturn value : %d\n", printf("|%+41.24d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%+41.24d|", 0) - 2);

// 	// printf("\treturn value : %d\n", printf("|%41.24d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%41.24d|", 0) - 2);

// 	// printf("\treturn value : %d\n", printf("|%0 41.24d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%0 41.24d|", 0) - 2);

// 	// printf("\treturn value : %d\n", printf("|%0+41.24d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%0+41.24d|", 0) - 2);

// 	// printf("\treturn value : %d\n", printf("|%041.24d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%041.24d|", 0) - 2);


// 	// printf("|%d|\n", 0) ;
// 	// printf("|%+d|\n", 0) ;
// 	// printf("|% d|\n", 0) ;

// 	printf("|%d|\n", 0) ;
// 	printf("|%5d|\n", 0) ;
// 	printf("|%.5d|\n", 0) ;
// 	printf("|%5.5d|\n", 0) ;
// 	printf("\n") ;
// 	printf("|%d|\n", 0) ;
// 	printf("|%*d|\n", 5, 0) ;
// 	printf("|%.*d|\n", 5, 0) ;
// 	printf("|%*.*d|\n", 5, 5, 0) ;
// 	printf("\n") ;

// 	ft_printf("|%d|\n", 0) ;
// 	ft_printf("|%5d|\n", 0) ;
// 	ft_printf("|%.5d|\n", 0) ;
// 	ft_printf("|%5.5d|\n", 0) ;
// 	ft_printf("\n") ;
// 	ft_printf("|%d|\n", 0) ;
// 	ft_printf("|%*d|\n", 5, 0) ;
// 	ft_printf("|%.*d|\n", 5, 0) ;
// 	ft_printf("|%*.*d|\n", 5, 5, 0) ;
// 	ft_printf("\n") ;


// 	printf("------------------\n") ;
// 	printf("------------------\n") ;



// 	// printf("\treturn value : %d\n", printf("|%i|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%i|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%.0i|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%.0i|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%.i|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%.i|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%5.0i|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%5.0i|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%5.i|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%5.i|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.i|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.i|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.0i|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.0i|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.1i|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.1i|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.2i|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.2i|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.3i|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.3i|", 0) - 2);
// 	// printf("------------------\n") ;
// 	// printf("\treturn value : %d\n", printf("|%i|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%i|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%.0i|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%.0i|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%.i|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%.i|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%5.0i|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%5.0i|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%5.i|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%5.i|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.i|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.i|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.0i|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.0i|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.1i|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.1i|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.2i|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.2i|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.3i|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.3i|", 56) - 2);
// 	// printf("\n\n") ;
// 	// printf("------------------\n") ;
// 	// printf("------------------\n") ;
// 	// printf("\n\n") ;
// 	// printf("\treturn value : %d\n", printf("|%d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%d|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%.0d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%.0d|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%.d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%.d|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%5.0d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%5.0d|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%5.d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%5.d|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.d|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.0d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.0d|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.1d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.1d|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.2d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.2d|", 0) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.3d|", 0) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.3d|", 0) - 2);
// 	// printf("------------------\n") ;
// 	// printf("\treturn value : %d\n", printf("|%d|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%d|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%.0d|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%.0d|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%.d|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%.d|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%5.0d|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%5.0d|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%5.d|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%5.d|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.d|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.d|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.0d|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.0d|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.1d|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.1d|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.2d|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.2d|", 56) - 2);
// 	// printf("\treturn value : %d\n", printf("|%-5.3d|", 56) - 2);
// 	// printf("\treturn value : %d\n\n", ft_printf("|%-5.3d|", 56) - 2);




// 	// number = 0 ;
// 	// printf("\treturn value : %d\n", printf("~%#25.1x~", number));
// 	// printf("\treturn value : %d\n\n", ft_printf("~%#25.1x~", number));
// 	// number = 0 ;
// 	// printf("\treturn value : %d\n", printf("42%49.2x42", number));
// 	// printf("\treturn value : %d\n\n", ft_printf("42%49.2x42", number));

// 	// number = -1779952590 ;
// 	// printf("\treturn value : %d\n", printf(">------------<%#51.38x>------------<", number));
// 	// printf("\treturn value : %d\n\n", ft_printf(">------------<%#51.38x>------------<", number));


// 	// number = -12345 ;
// 	// printf("\treturn value : %d\n", printf("~%10d~", number));
// 	// printf("\treturn value : %d\n\n", ft_printf("~%10d~", number));
// 	// number = 12345 ;
// 	// printf("\treturn value : %d\n", printf("~%-10d~", number));
// 	// printf("\treturn value : %d\n\n", ft_printf("~%-10d~", number));
// 	// number = -12345 ;
// 	// printf("\treturn value : %d\n", printf("~%-10d~", number));
// 	// printf("\treturn value : %d\n\n", ft_printf("~%-10d~", number));


// 	// number = -1009294037 ;
// 	// printf("\treturn value : %d\n", printf("!%16.10d!", number));
// 	// printf("\treturn value : %d\n\n", ft_printf("!%16.10d!", number));
// 	// number = -1563834385 ;
// 	// printf("\treturn value : %d\n", printf("!%48.40d!", number));
// 	// printf("\treturn value : %d\n\n", ft_printf("!%48.40d!", number));
// 	// number = 0 ;
// 	// printf("\treturn value : %d\n", printf("^.^/%14.8d^.^/", number));
// 	// printf("\treturn value : %d\n\n", ft_printf("^.^/%14.8d^.^/", number));
// 	// number = 624151006 ;
// 	// printf("\treturn value : %d\n", printf("\\!/% 61.2d\\!/", number));
// 	// printf("\treturn value : %d\n\n", ft_printf("\\!/% 61.2d\\!/", number));
// 	// number = -1742324628 ;
// 	// printf("\treturn value : %d\n", printf("^.^/% 52.2d^.^/", number));
// 	// printf("\treturn value : %d\n\n", ft_printf("^.^/% 52.2d^.^/", number));
// 	// number = 0 ;
// 	// printf("\treturn value : %d\n", printf("!% 24.2d!", number));
// 	// printf("\treturn value : %d\n\n", ft_printf("!% 24.2d!", number));
// 	// number = -1567090019 ;
// 	// printf("\treturn value : %d\n", printf("%12.11d", number));
// 	// printf("\treturn value : %d\n\n", ft_printf("%12.11d", number));

// // 	number = 12345 ;
// // 	printf("\treturn value : %d\n", printf("| |%d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%3.d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3.d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%3.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%8.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%8.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%3.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-8.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-8.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.9d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.9d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.10d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.10d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-5.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-5.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%40.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%40.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%20.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%20.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-40.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-40.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-20.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-20.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%40.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%40.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%20.40d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%20.40d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-40.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-40.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-20.40d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-20.40d| |\n", (number * -1)) - 7);


// // 	printf("------------------\n") ;
// // 	printf("------------------\n") ;


// // 	printf("\treturn value : %d\n", printf("| |%0d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%03d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%03d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%03.d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%03.d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%03.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%03.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%08.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%08.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%03.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%03.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%040.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%040.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%020.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%020.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%040.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%040.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%020.40d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%020.40d| |\n", (number * -1)) - 7);


// // 	printf("------------------\n") ;
// // 	printf("------------------\n") ;


// // 	printf("\treturn value : %d\n", printf("| |% d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% 3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% 3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% 3.d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% 3.d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% .3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% .3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% 3.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% 3.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% 8.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% 8.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% 3.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% 3.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% -8.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% -8.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% -3.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% -3.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% -3.9d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% -3.9d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% -3.10d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% -3.10d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% -5.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% -5.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% 40.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% 40.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% 20.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% 20.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% -40.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% -40.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% -20.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% -20.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% 40.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% 40.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% 20.40d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% 20.40d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% -40.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% -40.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n", printf("| |% -20.40d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |% -20.40d| |\n", (number * -1)) - 7);


// // 	printf("------------------\n") ;
// // 	printf("------------------\n") ;


// // 	printf("\treturn value : %d\n", printf("| |%+d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+3.d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+3.d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+3.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+3.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+8.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+8.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+3.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+3.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+-8.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+-8.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+-3.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+-3.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+-3.9d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+-3.9d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+-3.10d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+-3.10d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+-5.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+-5.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+40.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+40.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+20.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+20.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+-40.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+-40.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+-20.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+-20.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+40.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+40.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+20.40d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+20.40d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+-40.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+-40.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+-20.40d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+-20.40d| |\n", (number * -1)) - 7);


// // 	printf("------------------\n") ;
// // 	printf("------------------\n") ;


// // 	printf("\treturn value : %d\n", printf("| |%0+d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0+d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0+3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0+3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0+3.d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0+3.d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0+.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0+.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0+3.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0+3.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0+8.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0+8.3d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0+3.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0+3.8d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0+40.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0+40.20d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0+40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0+40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%+40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%+40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0+20.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0+20.40d| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0+40.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0+40.20d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0+20.40d| |\n", (number * -1)) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0+20.40d| |\n", (number * -1)) - 7);


// 	// printf("------------------\n") ;
// 	// printf("------------------\n") ;


// 	// printf("\treturn value : %d\n", printf("| |%04d| |", -14) - 7);
// 	// printf("\treturn value : %d\n\n", ft_printf("| |%04d| |", -14) - 7);
// 	// printf("\treturn value : %d\n", printf("| |%05d| |", -15) - 7);
// 	// printf("\treturn value : %d\n\n", ft_printf("| |%05d| |", -15) - 7);
// 	// printf("\treturn value : %d\n", printf("| |%06d| |", -16) - 7);
// 	// printf("\treturn value : %d\n\n", ft_printf("| |%06d| |", -16) - 7);


// // 	printf("------------------\n") ;
// // 	printf("------------------\n") ;

// // 	printf("\treturn value : %d\n", printf("| |%u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0u| |\n", number) - 7);
	
// // 	printf("\treturn value : %d\n", printf("| |%3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%03u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%03u| |\n", number) - 7);
	
// // 	printf("\treturn value : %d\n", printf("| |%5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%05u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%05u| |\n", number) - 7);
	
// // 	printf("\treturn value : %d\n", printf("| |%10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%010u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%010u| |\n", number) - 7);
	
// // 	printf("\treturn value : %d\n", printf("| |%.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0.3u| |\n", number) - 7);
	
// // 	printf("\treturn value : %d\n", printf("| |%.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0.5u| |\n", number) - 7);
	
// // 	printf("\treturn value : %d\n", printf("| |%.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0.10u| |\n", number) - 7);
	
// // 	printf("\treturn value : %d\n", printf("| |%3.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%03.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%03.3u| |\n", number) - 7);
	
// // 	printf("\treturn value : %d\n", printf("| |%3.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%03.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%03.5u| |\n", number) - 7);
	
// // 	printf("\treturn value : %d\n", printf("| |%3.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%03.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%03.10u| |\n", number) - 7);
	
// // 	printf("\treturn value : %d\n", printf("| |%5.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%5.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-5.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-5.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%05.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%05.3u| |\n", number) - 7);
	
// // 	printf("\treturn value : %d\n", printf("| |%5.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%5.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-5.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-5.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%05.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%05.5u| |\n", number) - 7);
	
// // 	printf("\treturn value : %d\n", printf("| |%5.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%5.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-5.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-5.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%05.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%05.10u| |\n", number) - 7);
	
// // 	printf("\treturn value : %d\n", printf("| |%10.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%10.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-10.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-10.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%010.3u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%010.3u| |\n", number) - 7);
	
// // 	printf("\treturn value : %d\n", printf("| |%10.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%10.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-10.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-10.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%010.5u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%010.5u| |\n", number) - 7);
	
// // 	printf("\treturn value : %d\n", printf("| |%10.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%10.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-10.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-10.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%010.10u| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%010.10u| |\n", number) - 7);

// // 	printf("------------------\n") ;
// // 	printf("------------------\n") ;

// // 	printf("\treturn value : %d\n", printf("| |%x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#x| |\n", number) - 7);
// // 	//sdf
// // 	printf("\treturn value : %d\n", printf("| |%x| |\n", 0) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%x| |\n", 0) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-x| |\n", 0) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-x| |\n", 0) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0x| |\n", 0) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0x| |\n", 0) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#x| |\n", 0) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#x| |\n", 0) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#x| |\n", 0) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#x| |\n", 0) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#x| |\n", 0) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#x| |\n", 0) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%03x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%03x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#3x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%04x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%04x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#4x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%05x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%05x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#5x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%010x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%010x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#10x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#.3x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#.4x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#.5x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#.10x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%3.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%03.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%03.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#3.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#3.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#3.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#3.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#3.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#3.3x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%3.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%03.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%03.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#3.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#3.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#3.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#3.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#3.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#3.4x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%3.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%03.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%03.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#3.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#3.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#3.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#3.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#3.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#3.5x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%3.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%03.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%03.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#3.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#3.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#3.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#3.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#3.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#3.10x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%5.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%5.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-5.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-5.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%05.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%05.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#5.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#5.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#5.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#5.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#5.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#5.3x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%5.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%5.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-5.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-5.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%05.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%05.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#5.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#5.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#5.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#5.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#5.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#5.4x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%5.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%5.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-5.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-5.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%05.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%05.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#5.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#5.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#5.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#5.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#5.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#5.5x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%5.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%5.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-5.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-5.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%05.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%05.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#5.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#5.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#5.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#5.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#5.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#5.10x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%10.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%10.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-10.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-10.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%010.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%010.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#10.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#10.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#10.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#10.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#10.3x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#10.3x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%10.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%10.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-10.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-10.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%010.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%010.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#10.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#10.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#10.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#10.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#10.4x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#10.4x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%10.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%10.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-10.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-10.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%010.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%010.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#10.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#10.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#10.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#10.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#10.5x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#10.5x| |\n", number) - 7);

// // 	printf("\treturn value : %d\n", printf("| |%10.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%10.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-10.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-10.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%010.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%010.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%#10.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%#10.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-#10.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-#10.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%0#10.10x| |\n", number) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%0#10.10x| |\n", number) - 7);


// // 	printf("==================\n") ;
// // 	printf("  SurPaddingOnADit\n") ;
// // 	printf("==================\n") ;

// // 	str = "12345" ;
// // 	printf("\treturn value : %d\n", printf("| |%s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%3.s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3.s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%5.s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%5.s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%10.s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%10.s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%.10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%.10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%3.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%3.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%3.10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3.10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%5.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%5.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%5.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%5.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%5.10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%5.10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%10.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%10.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%10.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%10.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%10.10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%10.10s| |\n", str) - 7);
// // 	printf("------------------\n") ;
// // 	printf("\treturn value : %d\n", printf("| |%-s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-5.s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-5.s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-10.s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-10.s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-.10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-.10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-5.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-5.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-5.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-5.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-5.10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-5.10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-10.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-10.3s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-10.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-10.5s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-10.10s| |\n", str) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-10.10s| |\n", str) - 7);

// 	// char *bibi = NULL;
// 	// printf("\treturn value : %d\n", printf("| |42%24.25s42| |\n", bibi) - 7);
// 	// printf("\treturn value : %d\n\n", ft_printf("| |42%24.25s42| |\n", bibi) - 7);
// 	// printf("\treturn value : %d\n", printf("| |42%58.2s42| |\n", bibi) - 7);
// 	// printf("\treturn value : %d\n\n", ft_printf("| |42%58.2s42| |\n", bibi) - 7);
// 	// printf("\treturn value : %d\n", printf("| |>------------<%31s>------------<| |\n", bibi) - 7);
// 	// printf("\treturn value : %d\n\n", ft_printf("| |>------------<%31s>------------<| |\n", bibi) - 7);

// // 	printf("==================\n") ;
// // 	printf(" MiniPaddingOnADit\n") ;
// // 	printf("==================\n") ;

// // 	char c = '1' ;
// // 	printf("\treturn value : %d\n", printf("| |%c| |\n", c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%c| |\n", c) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%3c| |\n", c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3c| |\n", c) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%3.c| |\n", c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3.c| |\n", c) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.c| |\n", c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.c| |\n", c) - 7);
// // 	printf("------------------\n") ;
// // 	printf("\treturn value : %d\n", printf("| |%-c| |\n", c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-c| |\n", c) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3c| |\n", c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3c| |\n", c) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3.c| |\n", c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3.c| |\n", c) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%--3.c| |\n", c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%--3.c| |\n", c) - 7);


// // 	printf("==================\n") ;
// // 	printf("  FacteurPadding\n") ;
// // 	printf("==================\n") ;

// // 	char *pc = &c ;
// // 	printf("\treturn value : %d\n", printf("| |%p| |\n", &c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%p| |\n", &c) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-p| |\n", &c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-p| |\n", &c) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%3p| |\n", &c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3p| |\n", &c) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%14p| |\n", &c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%14p| |\n", &c) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%20p| |\n", &c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%20p| |\n", &c) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3p| |\n", &c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3p| |\n", &c) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-14p| |\n", &c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-14p| |\n", &c) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-20p| |\n", &c) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-20p| |\n", &c) - 7);
// // 	printf("------------------\n") ;
// // 	printf("\treturn value : %d\n", printf("| |%p| |\n", pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%p| |\n", pc) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-p| |\n", pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-p| |\n", pc) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%3p| |\n", pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3p| |\n", pc) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%14p| |\n", pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%14p| |\n", pc) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%20p| |\n", pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%20p| |\n", pc) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3p| |\n", pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3p| |\n", pc) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-14p| |\n", pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-14p| |\n", pc) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-20p| |\n", pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-20p| |\n", pc) - 7);
// // 	printf("------------------\n") ;
// // 	printf("\treturn value : %d\n", printf("| |%p| |\n", &pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%p| |\n", &pc) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-p| |\n", &pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-p| |\n", &pc) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%3p| |\n", &pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3p| |\n", &pc) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%14p| |\n", &pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%14p| |\n", &pc) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%20p| |\n", &pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%20p| |\n", &pc) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3p| |\n", &pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3p| |\n", &pc) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-14p| |\n", &pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-14p| |\n", &pc) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-20p| |\n", &pc) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-20p| |\n", &pc) - 7);
// // 	printf("------------------\n") ;
// // 	printf("\treturn value : %d\n", printf("| |%p| |\n", NULL) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%p| |\n", NULL) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-p| |\n", NULL) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-p| |\n", NULL) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%3p| |\n", NULL) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%3p| |\n", NULL) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%14p| |\n", NULL) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%14p| |\n", NULL) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%20p| |\n", NULL) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%20p| |\n", NULL) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-3p| |\n", NULL) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-3p| |\n", NULL) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-14p| |\n", NULL) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-14p| |\n", NULL) - 7);
// // 	printf("\treturn value : %d\n", printf("| |%-20p| |\n", NULL) - 7);
// // 	printf("\treturn value : %d\n\n", ft_printf("| |%-20p| |\n", NULL) - 7);

// }