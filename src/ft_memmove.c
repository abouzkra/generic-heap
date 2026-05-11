/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:04:57 by abouzkra          #+#    #+#             */
/*   Updated: 2026/05/10 16:48:18 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!dest && !src)
		return (NULL);
	s = src;
	d = dest;
	if (d <= s)
	{
		while (n--)
			*(d++) = *(s++);
	}
	else
	{
		while (n--)
			*(d + n) = *(s + n);
	}
	return (dest);
}
