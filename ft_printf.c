/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoteris <noterisarthur42@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:16:24 by anoteris          #+#    #+#             */
/*   Updated: 2024/11/02 08:24:44 by anoteris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

__attribute__ ((format(printf, 1, 2))) int	ft_printf(const char *format, ...)
{
	(void) format ;
	return 0 ;
}

// #include <stdio.h>
// int main ()
// {
// 	int number = 10 ;
// 	printf("==================\n") ;
// 	printf("| |%d| |\n", number);
//     printf("| |%d| |\n", number);
//     printf("| |%x| |\n", number);  
//     printf("| |%x| |\n", number);
// 	printf("------------------\n") ;
// 	printf("| |%10d| |\n", number);
// 	printf("| |%-10d| |\n", number);
//     printf("| |%010d| |\n", number);
// 	printf("| |% 10d| |\n", number);
// 	printf("| |%+10d| |\n", number);
// 	printf("| |%  d| |\n", number);
// 	printf("| |%               d| |\n", number);
//     printf("| |%-#10x| |\n", number);  
//     printf("| |%-#10x| |\n", number);
//     printf("| |%#x| |\n", number);
//     printf("| |%#x| |\n", number);
// 	number = -10 ;
// 	printf("==================\n") ;
// 	printf("| |%d| |\n", number);
//     printf("| |%d| |\n", number);
//     printf("| |%x| |\n", number);  
//     printf("| |%x| |\n", number);
// 	printf("------------------\n") ;
// 	printf("| |%10d| |\n", number);
// 	printf("| |%-10d| |\n", number);
//     printf("| |%010d| |\n", number);
// 	printf("| |%010d| |\n", number);
//     printf("| |%-#10x| |\n", number);  
//     printf("| |%#x| |\n", number);
// 	number = 0 ;
// 	printf("==================\n") ;
// 	printf("| |%d| |\n", number);
//     printf("| |%d| |\n", number);
//     printf("| |%x| |\n", number);  
//     printf("| |%x| |\n", number);
// 	printf("------------------\n") ;
// 	printf("| |%10d| |\n", number);
// 	printf("| |%-10d| |\n", number);
//     printf("| |%010d| |\n", number);
// 	printf("| |%010d| |\n", number);
//     printf("| |%-#10x| |\n", number);  
//     printf("| |%#x| |\n", number);
// 	char *str = "abc";
// 	printf("==================\n") ;
// 	printf("| |%s| |\n", str);
//     printf("| |%s| |\n", str);
// 	printf("------------------\n") ;
// 	printf("| |%10s| |\n", str);
// 	printf("| |%-10s| |\n", str);
//     printf("| |%10.10s| |\n", str);
// 	printf("| |%10.5s| |\n", str);
// 	printf("| |%1.5s| |\n", str);
// 	printf("==================\n");
// 	str = "abcdefghijkl";
// 	printf("==================\n") ;
// 	printf("| |%s| |\n", str);
//     printf("| |%s| |\n", str);
// 	printf("------------------\n") ;
// 	printf("| |%10s| |\n", str);
// 	printf("| |%-10s| |\n", str);
//     printf("| |%10.10s| |\n", str);
// 	printf("| |%10.5s| |\n", str);
// 	printf("| |%40.20s| |\n", str);
// 	printf("| |%1.5s| |\n", str);
// 	printf("| |%1.s| |\n", str);
// 	printf("| |%1.0s| |\n", str);
// 	printf("| |%8.0s| |\n", str);
// 	printf("==================\n") ;
// 	printf("%d%d%d", 5) ;
// }