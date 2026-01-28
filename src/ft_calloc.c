/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:57:48 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/05 14:46:18 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_calloc - allocates and zeroes memory
 * @count: number of elements
 * @size: size of each element
 * Return: pointer to memory or NULL
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	if (size != 0 && count > INT_MAX / size)
		return (NULL);
	total = count * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
