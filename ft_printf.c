/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <olugash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:46:31 by olugash           #+#    #+#             */
/*   Updated: 2021/11/07 07:32:52 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_mod	*ft_init_mod(t_mod *mod)
{
	mod->flag_minus = 0;
	mod->flag_plus = 0;
	mod->flag_space = 0;
	mod->flag_oct = 0;
	mod->flag_zero = 0;
	mod->return_lenght = 0;
	mod->width = 0;
	mod->precision = 0;
	return (mod);
}

static const char	*check_format(const char *fmt, t_mod *mod)
{
	if (*fmt == '%')
	{
		fmt = ft_parse(fmt + 1, mod);
		return (fmt);
	}
	else
	{
		ft_putchar_fd(*fmt, 1);
		fmt++;
		mod->return_lenght++;
	}
	return (fmt);
}

int	ft_printf(const char *fmt, ...)
{
	t_mod	*mod;
	int		res;

	res = 0;
	mod = (t_mod *)malloc(sizeof(t_mod));
	if (!mod)
		return (-1);
	va_start(mod->arg, fmt);
	while (*fmt)
	{
		mod = ft_init_mod(mod);
		fmt = check_format(fmt, mod);
		if (!fmt)
			return (-1);
		res += mod->return_lenght;
	}
	free(mod);
	va_end(mod->arg);
	return (res);
}
