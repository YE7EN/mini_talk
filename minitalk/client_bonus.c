/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:11:49 by pjurdana          #+#    #+#             */
/*   Updated: 2025/01/21 13:49:45 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

char	**g_argv;

void	ft_signal(char **g_argv)
{
	char		bit;
	int			i;
	static int	j = 0;
	pid_t		pid;

	pid = ft_atoi(g_argv[1]);
	i = 7;
	while (i >= 0)
	{
		bit = (g_argv[2][j] >> i) & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(250);
	}
	if (g_argv[2][j] == '\0')
		exit (0);
	j++;
}

void	ft_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)ucontext ;
	(void)info;
	if (sig == SIGUSR1)
		ft_signal(g_argv);
	if (sig == SIGUSR2)
		write(1, "the string has been received", 28);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sig;

	ft_memset(&sig, 0, sizeof(sig));
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	if (argc != 3)
	{
		write(1, "error\n", 6);
		return (0);
	}
	g_argv = argv;
	pid = ft_atoi(g_argv[1]);
	if (pid < 1)
	{
		write(1, "Inapropriate use of PID", 23);
		return (1);
	}
	ft_signal(g_argv);
	while (1)
		pause();
	return (0);
}
