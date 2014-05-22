/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 20:16:03 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/22 21:02:30 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "libft.h"
#include "client.h"

void	write_server(SOCKET sock, const char *buffer)
{
	if (send(sock, buffer, ft_strlen(buffer), 0) < 0)
	{
		perror("send()");
		exit(errno);
	}
}
