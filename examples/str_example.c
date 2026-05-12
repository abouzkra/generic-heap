/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_example.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <abouzkra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:09:45 by abouzkra          #+#    #+#             */
/*   Updated: 2026/05/12 11:31:34 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/heap.h"
#include <string.h>

int	str_cmp(void *s1, void *s2)
{
	return (-strcmp((char *)s1, (char *)s2));
}

void	print_str(void *s1)
{
	printf("%s\n", *(char **)s1);
}

int	main(void)
{
	char *arr[5] = {"test", "hello", "Hello", "string", "adnan"};

	t_heap *q = heapify(arr, 5, sizeof(char *), str_cmp);
	pretty_print_heap(q, 0, 0, "", print_str);

	char* top;
	while (get_heap_count(q))
	{
		pop(q, &top);
		print_str(&top);
	}
	destroy_heap(q);
	return (0);
}
