/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_uns_numbers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <olugash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:41:26 by olugash           #+#    #+#             */
/*   Updated: 2021/11/06 16:43:50 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_uitoa(unsigned int un)
{
	char	*str;
	long	temp;
	int		len;

	len = 0;
	un += 4294967296;
	temp = un;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = un % 10 + '0';
		un /= 10;
	}
	return (str);
}

const char	*ft_processing_uns_numbers(t_mod *mod, const char *fmt)
{
	int		n;
	char	*str;
	int		len_arg;

	n = (va_arg(mod->arg, unsigned int));
	if (n < 0)
		str = ft_uitoa(n);
	else
		str = ft_itoa(n);
	len_arg = ft_strlen(str);
	mod->flag_space = 0;
	ft_print_str_of_numbers(str, len_arg, mod);
	free(str);
	return (++fmt);
}
