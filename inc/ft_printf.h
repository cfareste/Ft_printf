/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:54:20 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/13 12:37:36 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

// Main function
int		ft_printf(char const *str, ...);

// Print primitive
int		print_character(char c);
int		print_number(int n);
int		print_unsigned_number(unsigned int n);
int		print_string(char *str);

// Primitive helpers
char	*ft_uitoa(unsigned int n);

// Print complex
int		print_pointer(void *ptr);
int		print_hex_number(unsigned int n, char parameter);

// Complex helpers
int		calculate_total_hex_num_length(unsigned long n);
void	puthex_in_str(char *num_str, unsigned long n, int idx);
void	transform_hex_toupper(char *str);

#endif
