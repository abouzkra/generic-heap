/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <abouzkra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 17:01:06 by abouzkra          #+#    #+#             */
/*   Updated: 2026/05/10 17:01:41 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_swap(char *tmp, void *p1, void *p2, size_t width)
{
	if (!tmp || !p1 || !p2 || width == 0)
		return ;
	ft_memmove(tmp, p2, width);
	ft_memmove(p2, p1, width);
	ft_memmove(p1, tmp, width);
}
