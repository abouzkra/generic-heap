/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_example.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <abouzkra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:34:27 by abouzkra          #+#    #+#             */
/*   Updated: 2026/05/12 11:34:10 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/heap.h"
#include <time.h>

int	nb_cmp(void *x, void *y)
{
	return (*(int *)x - *(int *)y);
}

void	print_nb(void *x)
{
	printf("%d\n", *(int *)x);
}

int	main(void)
{
	srand(time(NULL));
	int	arr[10];

	for (int i=0; i < 10; i++)
		arr[i] = (rand() % 21) - 10;

	t_heap *q = heapify(arr, 10, sizeof(int), nb_cmp);
	pretty_print_heap(q, 0, 0, "", print_nb);

	int top;
	while (get_heap_count(q))
	{
		pop(q, &top);
		print_nb(&top);
	}
	destroy_heap(q);
	return (0);
}
