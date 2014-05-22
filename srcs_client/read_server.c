/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 20:20:42 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/22 21:02:09 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "client.h"

int		read_server(SOCKET sock, char *buffer)
{
	int 	n;

	n = 0;
	if((n = recv(sock, buffer, BUF_SIZE - 1, 0)) < 0)
	{
		perror("recv()");
		exit(errno);
	}
	buffer[n] = 0;
	return (n);
}
