/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <wchow@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:18:07 by wchow             #+#    #+#             */
/*   Updated: 2024/03/29 15:19:56 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

void	save_and_send(char c, int use);
void	end_string(unsigned int server_pid);
void	send_bits(int server_pid, char message_char);
void	first_signal(char first_char, unsigned int server_pid, int bits);

#endif