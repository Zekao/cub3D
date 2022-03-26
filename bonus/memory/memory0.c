/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:02:41 by ubuntu            #+#    #+#             */
/*   Updated: 2022/02/27 21:42:53 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static t_list	**memory(void)
{
	static t_list	*memory = NULL;

	return (&memory);
}

static void	push_memory(void *data)
{
	t_list	*ptr;

	ptr = malloc(sizeof(*ptr));
	if (!ptr)
		exit_failure("Out of memory");
	ptr->content = data;
	ptr->next = *memory();
	*memory() = ptr;
}

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr)
		push_memory(ptr);
	else
		exit_failure("Out of memory");
	return (ptr);
}

void	ft_free(void *addr)
{
	t_list	*ptr0;
	t_list	**ptr1;

	ptr1 = memory();
	ptr0 = *ptr1;
	while (ptr0 && ptr0->content != addr)
	{
		ptr1 = &ptr0->next;
		ptr0 = ptr0->next;
	}
	if (ptr0)
	{
		*ptr1 = ptr0->next;
		free(ptr0->content);
		free(ptr0);
	}
}

void	clear_memory(void)
{
	t_list	*ptr;

	while (*memory())
	{
		ptr = *memory();
		*memory() = ptr->next;
		free(ptr->content);
		free(ptr);
	}
}
