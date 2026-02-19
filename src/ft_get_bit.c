/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmouta-g <lmouta-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 12:07:36 by lmouta-g          #+#    #+#             */
/*   Updated: 2026/02/19 12:08:03 by lmouta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
/**
 * ps_get_bit - returns the value of a specific bit in an integer
 * @num: the number from which to extract the bit
 * @bit: position of the bit to get (starting from the right, 0-based)
 * Return: 0 if the bit is 0, 1 if the bit is 1
 */
int	ps_get_bit(int num, int bit)
{
	return ((num >> bit) & 1);
}
