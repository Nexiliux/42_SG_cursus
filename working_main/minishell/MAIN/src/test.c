/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 05:19:05 by wchow             #+#    #+#             */
/*   Updated: 2024/08/10 06:34:06 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test.h"

void	resetPrompt(int signum)
{
	(void)signum;
	write (1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ignore_sigquit(void)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}

void	process(char *input)
{
	if (!ft_strncmp(input, "echo ", 5))
		ft_printf("%s\n", input + 5);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	struct sigaction	sa;
	char	*input;
	printf("Only use echo for now.\n");

	ignore_sigquit();
	sa.sa_handler = &resetPrompt;
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	while (1)
	{
		input = readline("<<Nanoshell>>  ");
		if (input && *input)
		{
			add_history(input); // Add to history if input is not empty
			process(input);
			free(input);
		}
		else if (input == NULL) // Handle Ctrl+D (EOF)
		{
			printf("exit\n");
			break;
		}
	}
	return (0);
}