/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_example.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <abouzkra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 11:41:47 by abouzkra          #+#    #+#             */
/*   Updated: 2026/05/11 11:50:07 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/heap.h"

typedef struct s_task
{
	size_t	priority;
	char	name[16];
}	t_task;

int	task_cmp(void *task1, void *task2)
{
	return ((t_task *)task1)->priority - ((t_task *)task2)->priority;
}

void	print_task(void	*task1)
{
	printf("{%s: %ld}\n", ((t_task *)task1)->name, ((t_task *)task1)->priority);
}

int	main(void)
{
	t_task	arr[5] = {
		(t_task){.priority=10, .name="task1"},
		(t_task){.priority=1, .name="task2"},
		(t_task){.priority=8, .name="task3"},
		(t_task){.priority=6, .name="task4"},
		(t_task){.priority=3, .name="task5"},
	};

	t_heap	*q = heapify(arr, 5, sizeof(t_task), task_cmp);
	pretty_print_q(q, 0, 0, "", print_task);

	printf("\n");
	t_task	top;
	while (q->count)
	{
		pop(q, &top);
		print_task(&top);
	}
	return (0);
}
