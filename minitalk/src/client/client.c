/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:20:09 by wchow             #+#    #+#             */
/*   Updated: 2024/05/21 16:24:28 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../printf/includes/ft_printf.h"
#include "../../minitalk.h"

char	**g_argv;

void	end_string(unsigned int server_pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		kill(server_pid, SIGUSR2);
		i--;
		usleep(1000);
	}
}

void	send_bits(int server_pid, char message_char)
{
	int		bits;
	char	current_char;

	current_char = message_char;
	bits = 7;
	while (bits >= 0)
	{
		if (current_char & (1 << bits))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		bits--;
		usleep(1000);
	}
}

void	first_signal(char first_char, unsigned int server_pid, int bits)
{
	if (first_char && first_char != '\0')
	{
		while (bits >= 0)
		{
			if (first_char & (1 << bits))
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			bits--;
			usleep(1000);
		}
	}
}

void	sig_handler(int sig)
{
	unsigned int	server_pid;
	static int		i = 1;
	static char			*message = NULL;

	server_pid = ft_atoi(g_argv[1]);
	if (!message)
		message = ft_strdup(g_argv[2]);
	if (sig == SIGUSR2)
	{
		free(message);
		ft_printf("Server acknowledges end of string. My time has come...\n");
		exit(0);
	}
	if (sig == SIGUSR1 && message[i] == '\0')
		end_string(server_pid);
	else if (sig == SIGUSR1)
	{
		send_bits(server_pid, message[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3 || !argv[2])
	{
		ft_printf("Usage: [./client] [server_pid] [your_message]\n");
		exit(0);
	}
	if (ft_atoi(argv[1]) <= 0)
	{
		ft_printf("server_pid cannot be less than or equal to zero.\n");
		exit(0);
	}
	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	g_argv = argv;
	if (g_argv[2][0] && g_argv[2][0] != '\0')
		first_signal(g_argv[2][0], ft_atoi(g_argv[1]), 7);
	while (1)
		sleep(1);
	return (0);
}
