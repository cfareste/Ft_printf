/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:54:20 by cfidalgo          #+#    #+#             */
/*   Updated: 2024/02/15 21:28:11 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../libft/libft.h"
# include <stdarg.h>

// Structs types
typedef struct s_flags
{
	int	minus;
	int	plus;
	int	space;
	int	hashtag;
	int	zero;
	int	width;
	int	precision;
}	t_flags;

// Main function
int		ft_printf(char const *str, ...);

// Print primitive
int		print_character(char c, t_flags *flags);
int		print_raw_char(char c);
int		print_number(int n, t_flags *flags);
int		print_sig_number_string(char *num_str, t_flags *flags, int n);
int		print_unsigned_number(unsigned int n, t_flags *flags);
int		print_uns_number_string(char *num_str, t_flags *flags, unsigned int n);
int		print_string(char *str, t_flags *flags);
int		print_raw_string(char *str);

// Primitive helpers
char	*ft_uitoa(unsigned int n);

// Print complex
int		print_pointer(void *ptr, t_flags *flags);
int		print_hex_number(unsigned int n, char parameter, t_flags *flags);
int		print_hex_nb_str(char *n_str, t_flags *flags, char pm, unsigned int n);

// Complex helpers
int		calculate_total_hex_num_length(unsigned long n);
void	puthex_in_str(char *num_str, unsigned long n, int idx);
void	transform_hex_toupper(char *str);

// Common helpers
int		print_width(int bytes, char byte_to_print);
void	process_precision(char *str, t_flags *flags);
int		calculate_width(char *str, t_flags *flags);
int		print_precised_string(char *str, int precision);
int		check_for_signs_flags(int n, t_flags *flags);

// Parsed helpers
int		print_precised_number(char *num_str, t_flags *flags, unsigned int n);
int		calc_total_width(char *num_str, t_flags *flags, int bytes_written);
int		print_hex_prefix(unsigned int n, char parameter);

// Struct helpers
void	reset_flags(t_flags *flags);
t_flags	*initialize_flags(void);
int		free_flags_struct(t_flags *flags, int final_length);

// Handle flags helpers
int		count_flags(char const *str, int *pos, t_flags *flags);

#endif
