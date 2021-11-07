/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_of_numbers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <olugash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:06:01 by olugash           #+#    #+#             */
/*   Updated: 2021/11/06 17:06:49 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void	print(t_mod *mod, size_t count_space, size_t count_zero, char *s)
{
	if (!mod->flag_minus)
		ft_print_space(count_space, mod);
	if (mod->flag_plus)
		ft_putchar_fd(mod->flag_plus, 1);
	if (mod->flag_space)
	{
		ft_putchar_fd(' ', 1);
		mod->return_lenght++;
	}
	mod->return_lenght += count_zero;
	while (count_zero-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(s, 1);
	if (mod->flag_minus)
		ft_print_space(count_space, mod);
}

void	ft_print_str_of_numbers(char *s, size_t len_arg, t_mod *mod)
{
	size_t	count_zero;
	size_t	count_space;

	count_zero = 0;
	count_space = 0;
	if (mod->precision == -1 && *s == '0')
	{
		*s = 0;
		len_arg = 0;
	}
	if (mod->precision > (int)len_arg)
		count_zero = mod->precision - len_arg;
	if (mod->width > mod->precision && mod->width > (int)len_arg)
		count_space = mod->width - len_arg - mod->return_lenght - count_zero;
	if (mod->flag_zero)
	{
		count_zero = count_space;
		count_space = 0;
	}
	print(mod, count_space, count_zero, s);
	mod->return_lenght += len_arg;
}
