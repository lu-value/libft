/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:53:45 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/05 09:45:02 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_toupper - converts lowercase to uppercase
 * @c: character to convert
 * Return: uppercase char or c unchanged
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}
