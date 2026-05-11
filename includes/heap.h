/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <abouzkra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:10:14 by abouzkra          #+#    #+#             */
/*   Updated: 2026/05/11 10:01:29 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_heap
{
	void	*data;
	size_t	cap;
	size_t	count;
	size_t	width;
	int		(*cmp)(void *el1, void *el2);
	char	*swap;
}	t_heap;

t_heap	*create_heap(
			size_t cap,
			size_t width,
			int (*cmp)(void *el1, void *el2)
			);
t_heap	*heapify(
			void *arr,
			size_t cap,
			size_t width,
			int (*cmp)(void *el1, void *el2)
			);
void	insert(t_heap *q, void *data);
void	pop(t_heap *q, void *dest);
void	del(t_heap *q, size_t idx);
void	destroy_heap(t_heap *q);
void	pretty_print_q(
			t_heap *q, size_t idx, size_t depth,
			char *prefix, void (*print_data)(void *data)
			);

#endif
