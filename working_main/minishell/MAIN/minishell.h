/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:39:37 by wchow             #+#    #+#             */
/*   Updated: 2024/09/10 16:45:02 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
#include "./libft/libft.h"
#include "./printf/includes/ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

//Messages
# define showCmds "Custom commands: echo | env | exit | showpath\nSystem commands: non-argument syscalls might work e.g. ls | pwd\n"

typedef struct s_data
{
	char	**env;
	char	*path;
	//char	*input;
}	t_data;

//Initialisation
void	initData(t_data *data, char **env);

//Signals
void	handleSignals();
void	ignore_sigquit();
void	resetPrompt(int signum);

//Processing
void	start(t_data *data);
void	process(char *input, t_data *data);

//Builtins
void	ft_echo(char *input);
int	checkNewline(char *input);

//Exit
void	freeData(t_data *data);

#endif