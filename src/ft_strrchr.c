/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:49:02 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/18 13:21:02 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strrchr - finds last occurrence of c in str
 * @str: string to search
 * @c: character to find
 * Return: pointer to char or NULL
 */
char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str) + 1;
	while (i--)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
	}
	return (NULL);
}
