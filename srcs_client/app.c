/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 20:28:55 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/23 17:25:41 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/select.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "libft.h"
#include "client.h"

void	app(const char *address, const int port)
{
	SOCKET		sock = init_connection(address, port);
	char		buffer[BUF_SIZE];
	fd_set		rdfs;
	char		*line;

	/* send our name */
	/*write_server(sock, name);*/

	while(1)
	{
		FD_ZERO(&rdfs);

		/* add STDIN_FILENO */
		FD_SET(STDIN_FILENO, &rdfs);

		/* add the socket */
		FD_SET(sock, &rdfs);

		if(select(sock + 1, &rdfs, NULL, NULL, NULL) == -1)
		{
			perror("select()");
			exit(errno);
		}

		/* something from standard input : i.e keyboard */
		if(FD_ISSET(STDIN_FILENO, &rdfs))
		{
			if (get_next_line(STDIN_FILENO, &line) > 0)
				write_server(sock, line);
			/*
			fgets(buffer, BUF_SIZE - 1, stdin);
			{
				char *p = NULL;
				p = ft_strstr(buffer, "\n");
				if(p != NULL)
				{
					*p = 0;
				}
				else
				{
					// fclean
					buffer[BUF_SIZE - 1] = 0;
				}
			}
			write_server(sock, buffer);
			*/
		}
		else if(FD_ISSET(sock, &rdfs))
		{
			int n = read_server(sock, buffer);
			/* server down */
			if(n == 0)
			{
				printf("Server disconnected !\n");
				break;
			}
			ft_putstr(buffer);
			// puts(buffer);
		}
	}

	end_connection(sock);
}
