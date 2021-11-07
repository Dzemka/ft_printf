/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <olugash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:32:39 by olugash           #+#    #+#             */
/*   Updated: 2021/11/06 21:36:14 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_mod
{
	va_list	arg;
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		flag_oct;
	int		flag_zero;
	int		return_lenght;
	int		width;
	int		precision;
}	t_mod;
int				ft_printf(const char *fmt, ...);
const char		*ft_parse(const char *fmt, t_mod *mod);
const char		*ft_processing(t_mod *mod, const char *fmt);
const char		*ft_processing_char(t_mod *mod, const char *fmt);
const char		*ft_processing_string(t_mod *mod, const char *fmt);
const char		*ft_processing_pointer(t_mod *mod, const char *fmt);
const char		*ft_processing_numbers(t_mod *mod, const char *fmt);
const char		*ft_processing_uns_numbers(t_mod *mod, const char *fmt);
const char		*ft_processing_hexidecimal(t_mod *mod, const char *fmt);
void			ft_print_space(size_t count_space, t_mod *mod);
void			ft_print_str_of_numbers(char *s, size_t len_arg, t_mod *mod);
char			*ft_itoa_hexidecimal(size_t p);
#endif
