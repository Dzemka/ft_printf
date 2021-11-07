/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexidecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <olugash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:08:59 by olugash           #+#    #+#             */
/*   Updated: 2021/11/06 23:38:16 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hexidecimal_base(size_t p)
{
	size_t	base;

	base = p;
	while (base % 16 > 0)
		base--;
	return (base);
}

static char	*fill_hex_str(char *str, size_t p, int len)
{
	char	s;

	str[len--] = '\0';
	while (len >= 0)
	{
		s = p - hexidecimal_base(p) + 48;
		p /= 16;
		if (s > 57)
			s += 39;
		str[len--] = s;
	}
	return (str);
}

char	*ft_itoa_hexidecimal(size_t p)
{
	int		len;
	char	*str;
	size_t	temp;

	len = 0;
	temp = p;
	if (p == 0)
		len = 1;
	while (temp)
	{
		temp /= 16;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	return (fill_hex_str(str, p, len));
}
