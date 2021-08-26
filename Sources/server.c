/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 10:06:16 by mboy              #+#    #+#             */
/*   Updated: 2021/08/26 10:18:27 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minitalk.h"

t_mini	*server_initiate(void)
{
	t_mini	*talk;

	talk = malloc(sizeof(t_mini));
	if (!talk)
	{
		ft_putstr("[ERROR]: Out of memory! malloc() failed.\n");
		exit(EXIT_FAILURE);
	}
	talk->pid_server = 0;
	talk->pid_client = 0;
	return (talk);
}

void	server_receive(int binary)
{
	static int		bit = 0;
	static char		letter = 0;

	letter += ((binary & 1) << bit++);
	if (bit == 7)
	{
		write(1, &letter, 1);
		if (!letter)
			write(1, "\n", 1);
		letter = 0;
		bit = 0;
	}
	return ;
}

void	server_loop(t_mini *talk)
{
	while (42)
	{
		if ((signal(SIGUSR1, server_receive) == SIG_ERR)
			|| (signal(SIGUSR2, server_receive) == SIG_ERR))
		{
			ft_putstr("[ERROR]: Signal error.\n");
			free(talk);
			talk = NULL;
			exit(EXIT_FAILURE);
		}
		pause();
	}
	return ;
}

int	main(int ac, char *av[])
{
	t_mini	*talk;

	(void)av;
	talk = NULL;
	if (ac != 1)
	{
		ft_putstr("[ERROR]: Use ./server with 1 argument only.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = server_initiate();
		talk->pid_server = getpid();
		ft_putstr("[SUCCESS]: Server ready! PID: ");
		ft_putnbr(talk->pid_server);
		write(1, "\n", 1);
		server_loop(talk);
	}
	free(talk);
	talk = NULL;
	return (0);
}
