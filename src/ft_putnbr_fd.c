/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:29:41 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/12 13:29:44 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_putnbr_fd - writes integer to fd
 * @n: integer to write
 * @fd: file descriptor
 */
void	ft_putnbr_fd(int n, int fd)
{
	char	buf[12];
	int		i;
	long	nb;

	if (fd < 0)
		return ;
	nb = n;
	i = 0;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	while (nb > 0)
	{
		buf[i++] = nb % 10 + '0';
		nb /= 10;
	}
	while (i--)
		ft_putchar_fd(buf[i], fd);
}
