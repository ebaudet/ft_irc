/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 20:16:30 by ebaudet           #+#    #+#             */
/*   Updated: 2014/05/23 16:36:13 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <arpa/inet.h>

# define INVALID_SOCKET -1
# define SOCKET_ERROR -1

typedef int					SOCKET;
typedef struct sockaddr_in	SOCKADDR_IN;
typedef struct sockaddr		SOCKADDR;
typedef struct in_addr		IN_ADDR;

# define PORT		4242

# define BUF_SIZE	1024

/*
** write_server.c
*/
void	write_server(SOCKET sock, const char *buffer);

/*
** read_server.c
*/
int		read_server(SOCKET sock, char *buffer);

/*
** read_server.c
*/
void	end_connection(int sock);

/*
** init_connection.c
*/
int		init_connection(const char *address, int port);

/*
** app.c
*/
void	app(const char *address, const int port);

#endif
