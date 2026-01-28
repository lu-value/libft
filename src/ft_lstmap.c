/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lm0uta <lmouta-g@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:06:09 by lm0uta            #+#    #+#             */
/*   Updated: 2025/11/13 16:06:12 by lm0uta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_and_return_null(t_list **result, void (*del)(void *))
{
	if (result)
		ft_lstclear(result, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
			return (free_and_return_null(&result, del));
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			return (free_and_return_null(&result, del));
		}
		ft_lstadd_back(&result, new_node);
		lst = lst->next;
	}
	return (result);
}
