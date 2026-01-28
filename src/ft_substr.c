/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:59:16 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/06 13:48:31 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_substr - extracts substring from s
 * @s: source string
 * @start: start index
 * @len: max length
 * Return: new allocated substring or NULL
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	sub_len = len;
	if (s_len - start < sub_len)
		sub_len = s_len - start;
	substr = (char *)malloc(sub_len + 1);
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, sub_len);
	substr[sub_len] = '\0';
	return (substr);
}
