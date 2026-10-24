/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabed <yaabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:22:32 by yaabed            #+#    #+#             */
/*   Updated: 2026/10/24 13:47:13 by yaabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	add_number(t_list **stack, int number)
{
	t_list	*node;
	int		*value;

	if (!stack)
		return (0);
	value = malloc(sizeof(int));
	if (!value)
		return (0);
	*value = number;
	node = ft_lstnew(value);
	if (!node)
	{
		free(value);
		return (0);
	}
	ft_lstadd_back(stack, node);
	return (1);
}

void	del(void *content)
{
	free(content);
}

void	remove_stack(t_list **stack)
{
	if (!stack)
		return ;
	ft_lstclear(stack, del);
}
