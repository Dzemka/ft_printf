/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <olugash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:49:48 by olugash           #+#    #+#             */
/*   Updated: 2021/11/06 16:49:57 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_processing_numbers(t_mod *mod, const char *fmt)
{
	char	*s;
	size_t	len_arg;

	s = ft_itoa(va_arg(mod->arg, int));
	if (!s)
		return (NULL);
	len_arg = ft_strlen(s);
	if (*s == '-' || mod->flag_plus)
	{
		if (*s != '-')
			mod->flag_plus = '+';
		else
		{
			mod->flag_plus = '-';
			s = ft_memcpy(s, s + 1, len_arg);
			len_arg--;
		}
		mod->return_lenght++;
		mod->flag_space = 0;
	}
	ft_print_str_of_numbers(s, len_arg, mod);
	free(s);
	return (++fmt);
}
