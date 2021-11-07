/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <olugash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:48:10 by olugash           #+#    #+#             */
/*   Updated: 2021/11/06 16:49:09 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void	ft_print_string(char *s, t_mod *mod)
{
	size_t	len_arg;
	char	*str;

	len_arg = ft_strlen(s);
	if (mod->precision && mod->precision < (int)len_arg)
	{
		if (mod->precision == -1)
			mod->precision++;
		str = (char *)malloc(sizeof(char) * (mod->precision + 1));
		if (!s)
			return ;
		ft_strlcpy(str, s, mod->precision + 1);
		len_arg = mod->precision;
		s = str;
		free(str);
	}
	if (mod->width > (int)len_arg && !mod->flag_minus)
		ft_print_space(mod->width - len_arg, mod);
	ft_putstr_fd(s, 1);
	if (mod->width > (int)len_arg && mod->flag_minus)
		ft_print_space(mod->width - len_arg, mod);
	mod->return_lenght += len_arg;
}

const char	*ft_processing_string(t_mod *mod, const char *fmt)
{
	char	*s;

	s = va_arg(mod->arg, char *);
	if (s)
		ft_print_string(s, mod);
	else
		ft_print_string("(null)", mod);
	return (++fmt);
}
