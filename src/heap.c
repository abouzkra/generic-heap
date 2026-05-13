/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <abouzkra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:09:42 by abouzkra          #+#    #+#             */
/*   Updated: 2026/05/12 11:29:57 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/heap.h"
#include "utils.h"

struct s_heap
{
	void	*data;
	size_t	cap;
	size_t	count;
	size_t	width;
	int		(*cmp)(void *el1, void *el2);
	char	*swap;
};

static void	*get_node(t_heap *q, size_t i)
{
	if (i < q->count)
		return ((char *)q->data + q->width * i);
	return (NULL);
}

static void	sift_up(t_heap *q, size_t idx)
{
	void	*parent;
	void	*child;
	size_t	i;

	i = idx;
	while (i > 0)
	{
		parent = get_node(q, ((size_t)(i - 1) / 2));
		child = get_node(q, i);
		if (q->cmp(parent, child) < 0)
			ft_swap(q->swap, parent, child, q->width);
		else
			break ;
		i = (size_t)(i - 1) / 2;
	}
}

static void	sift_down(t_heap *q, size_t idx)
{
	void	*parent;
	void	*l_child;
	void	*r_child;
	size_t	i;
	size_t	best;

	i = idx;
	while ((i * 2 + 1) < q->count)
	{
		parent = get_node(q, i);
		l_child = get_node(q, i * 2 + 1);
		r_child = get_node(q, i * 2 + 2);
		best = i * 2 + 1;
		if (r_child && q->cmp(l_child, r_child) < 0)
			best = i * 2 + 2;
		if (l_child && q->cmp(parent, get_node(q, best)) < 0)
		{
			ft_swap(q->swap, parent, get_node(q, best), q->width);
			i = best;
		}
		else
			break ;
	}
}

static void	prepare_prefix(char *old_prefix, char *new_prefix, int is_left)
{
	int	j;

	j = 0;
	while (old_prefix[j])
	{
		new_prefix[j] = old_prefix[j];
		j++;
	}
	if (is_left)
	{
		new_prefix[j++] = '|';
		new_prefix[j++] = ' ';
	}
	else
	{
		new_prefix[j++] = ' ';
		new_prefix[j++] = ' ';
	}
	new_prefix[j++] = '\0';
}

t_heap	*create_heap(size_t cap, size_t	width, int (*cmp)(void *el1, void *el2))
{
	t_heap	*q;

	q = (t_heap *)malloc(sizeof(t_heap));
	if (!q)
		return (NULL);
	q->data = malloc(width * cap);
	if (!q->data)
		return (free(q), NULL);
	ft_memset(q->data, 0, width * cap);
	q->swap = (char *)malloc(width);
	if (!q->swap)
		return (free(q->data), free(q), NULL);
	q->cap = cap;
	q->count = 0;
	q->width = width;
	q->cmp = cmp;
	return (q);
}

t_heap	*heapify(
			void *arr,
			size_t cap,
			size_t width,
			int (*cmp)(void *el1, void *el2)
			)
{
	t_heap	*q;
	size_t	i;

	if (!arr || cap == 0)
		return (NULL);
	q = create_heap(cap, width, cmp);
	if (!q)
		return (NULL);
	q->count = cap;
	ft_memmove(q->data, arr, width * cap);
	i = q->count / 2;
	while (i > 0)
	{
		i--;
		sift_down(q, i);
	}
	return (q);
}

void	insert(t_heap *q, void *data)
{
	if (q->count == q->cap)
		return ;
	ft_memmove((char *)q->data + (q->width * q->count), data, q->width);
	q->count++;
	sift_up(q, q->count - 1);
}

size_t	get_heap_count(t_heap *q)
{
	return (q->count);
}

void	pop(t_heap *q, void *dest)
{
	if (q->count == 0)
		return ;
	ft_memmove(dest, q->data, q->width);
	ft_memmove(q->data, (char *)q->data + q->width * (q->count - 1), q->width);
	q->count--;
	sift_down(q, 0);
}

void	del(t_heap *q, size_t idx)
{
	if (q->count == 0 || idx >= q->count)
		return ;
	ft_memmove(
		(char *)q->data + q->width * idx,
		(char *)q->data + q->width * (q->count -1),
		q->width);
	q->count--;
	sift_down(q, idx);
	sift_up(q, idx);
}

void	destroy_heap(t_heap *q)
{
	free(q->data);
	free(q->swap);
	free(q);
}

void	pretty_print_heap(
	t_heap *q, size_t idx, size_t depth,
	char *prefix,
	void (*print_data)(void *data))
{
	char	new_prefix[256];

	if (idx >= q->count)
		return ;
	printf("%s", prefix);
	if (idx % 2 == 1 && idx != 0)
		printf("├──── ");
	else if (idx != 0 && idx % 2 == 0)
		printf("└──── ");
	print_data((char *)q->data + idx * q->width);
	prepare_prefix(prefix, new_prefix, idx % 2 == 1);
	pretty_print_heap(q, idx * 2 + 1, depth + 1, new_prefix, print_data);
	pretty_print_heap(q, idx * 2 + 2, depth + 1, new_prefix, print_data);
}
