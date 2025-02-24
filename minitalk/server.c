/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjurdana <pjurdana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:26:05 by pjurdana          #+#    #+#             */
/*   Updated: 2025/01/21 15:14:29 by pjurdana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	g_index = 0;

void	*ft_alloc(char *string, int g_index, char c)
{
	char	*tmp;
	int		i;

	tmp = malloc(sizeof(char) * (g_index + 1));
	if (!tmp)
		return (NULL);
	if (string != NULL)
	{
		i = 0;
		while (i < g_index)
		{
			tmp[i] = string[i];
			i++;
		}
		free(string);
		string = NULL;
	}
	tmp[g_index] = c;
	return (tmp);
}

void	bits_to_char(unsigned long *bits)
{
	static char	*string = NULL;
	static char	c = 0;
	static int	i = 0;

	while (i < 8)
	{
		c = c << 1;
		if (bits[i] == 1)
			c |= 1;
		i++;
	}
	if (c == '\0')
	{
		write (1, string, g_index);
		free(string);
		string = NULL;
		g_index = 0;
	}
	else if (i == 8)
	{
		string = ft_alloc(string, g_index, c);
		g_index++;
	}
	i = 0;
}

void	ft_handler(int sig, siginfo_t *info, void *ucontext)
{
	pid_t					pid_client;
	static unsigned long	bits[8];
	static int				i = 0;

	pid_client = info->si_pid;
	(void)ucontext;
	(void)info;
	if (sig == SIGUSR1)
		bits[i++] = 1;
	if (sig == SIGUSR2)
		bits[i++] = 0;
	if (i == 8)
	{
		bits_to_char(bits);
		i = 0;
		usleep(250);
		kill(pid_client, SIGUSR1);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	ft_memset(&sig, 0, sizeof(sig));
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_handler;
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
