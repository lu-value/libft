/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lu-value <lu-value@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 00:00:00 by lu-value          #+#    #+#             */
/*   Updated: 2026/04/10 00:00:00 by lu-value         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	put_hex_rec(unsigned long long value)
{
	int	len;

	len = 0;
	if (value >= 16)
		len += put_hex_rec(value / 16);
	len += ft_putchar("0123456789abcdef"[value % 16]);
	return (len);
}

int	ft_putpointer(unsigned long long ptr)
{
	int	len;

	if (ptr == 0)
		return (ft_putstr("(nil)"));
	len = 0;
	len += ft_putstr("0x");
	len += put_hex_rec(ptr);
	return (len);
}
