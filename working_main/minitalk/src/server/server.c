/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:20:16 by wchow             #+#    #+#             */
/*   Updated: 2024/03/29 15:20:18 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../printf/includes/ft_printf.h"
#include "../../minitalk.h"

void	save_and_send(char c, int use)
{
	static char	*result = NULL;
	static int	i = 0;
	char		*temp;

	if (!result && c && use == 1)
		result = ft_strdup(&c);
	else if (result[i] && c && use == 1)
	{
		temp = ft_strjoin(result, &c);
		if (temp)
			free(result);
		result = temp;
		i++;
	}
	if (use == 2)
	{
		ft_printf("%s\n", result);
		free (result);
		result = NULL;
		i = 0;
	}
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	bits = 0;
	static char	current_char = 0;

	(void)context;
	current_char <<= 1;
	if (sig == SIGUSR1)
		current_char |= 1;
	bits++;
	if (bits == 8 && current_char == '\0')
	{
		kill(info->si_pid, SIGUSR2);
		save_and_send(current_char, 2);
		bits = 0;
		current_char = 0;
	}
	else if (bits == 8)
	{
		save_and_send(current_char, 1);
		bits = 0;
		current_char = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	ft_printf("Server PID: %d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}
