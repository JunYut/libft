/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:23:51 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/16 12:13:24 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*temp;

	if (list == NULL || *list == NULL)
		return ;
	while (*list != NULL)
	{
		temp = (*list)->next;
		ft_lstdelone(*list, del);
		*list = temp;
	}
	list = NULL;
}

/*
#include <unistd.h>
#include <string.h>

void	ft_print_result(t_list *elem)
{
	write(1, elem->content, strlen(elem->content));
}

static int	nb_free_done;

void	ft_del(void *content)
{
	free(content);
	nb_free_done++;
}

t_list	*ft_lstnewone(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (!content)
		elem->content = NULL;
	else
		elem->content = content;
	elem->next = NULL;
	return (elem);
}

int main(void)
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = strdup("lorem");
	char		*str2 = strdup("ipsum");
	char		*str3 = strdup("dolor");
	char		*str4 = strdup("sit");

	elem = ft_lstnewone(str);
	elem2 = ft_lstnewone(str2);
	elem3 = ft_lstnewone(str3);
	elem4 = ft_lstnewone(str4);
	alarm(5);
	if (!elem || !elem2 || !elem3 || !elem4)
		return (0);
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	nb_free_done = 0;
	ft_lstclear(&elem3, &ft_del);
	if (elem)
		ft_print_result(elem);
	else
		write(1, "NULL", 4);
	write(1, "\n", 1);
	if (elem2)
		ft_print_result(elem2);
	else
		write(1, "NULL", 4);
	write(1, "\n", 1);
	if (elem3)
		ft_print_result(elem3);
	else
		write(1, "NULL", 4);
	write(1, "\n", 1);
	if (elem4)
	{
		write(1, "nb_free_done = ", 15);
		nb_free_done += '0';
		write(1, &nb_free_done, 1);
	}
	else
		write(1, "NULL", 4);
	return (0);
}
*/