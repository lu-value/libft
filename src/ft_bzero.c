/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:23:03 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/04 13:03:31 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_bzero - sets memory to zero
 * @b: pointer to memory
 * @len: number of bytes
 */
void	ft_bzero(void *b, size_t len)
{
	ft_memset(b, 0, len);
}
