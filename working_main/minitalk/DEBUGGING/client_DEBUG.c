#include "../../libft/libft.h"
#include "../../printf/includes/ft_printf.h"
#include "../../minitalk.h"

char	**global_argv;

void	end_process(unsigned int server_pid)
{
	int	i;
	char	c = '\0';

	printf("End Process started\n");
	printf("c is: %c\n", c);
	i = 7;
	while (i >= 0)
	{
		kill(server_pid, SIGUSR2);
		printf("bit = 0 sent\n");
		i--;	
		usleep(1000);
	}	
	exit(0);
}

void	sig_handler(int	sig)
{
	unsigned int	server_pid;
	char	*message;
	char	current_char;
	static int	i = 1;
	int	bits;

	server_pid = ft_atoi(global_argv[1]);
	message = ft_strdup(global_argv[2]);
	if (sig == SIGUSR1 && message[i] == '\0')
	{
		printf("Ending sighandler\n");
		free(message);
		end_process(server_pid);
		exit(0);
	}
	if (sig == SIGUSR1)
	{
		printf("Server acknowledgement received\n");
		current_char = message[i];
		bits = 7;
		while (bits >= 0)
		{
			if (current_char & (1 << bits)){
				kill(server_pid, SIGUSR1);
				printf("bit = 1 sent\n");}
			else{
				kill(server_pid, SIGUSR2);
				printf("bit = 0 sent\n");}
			bits--;	
			usleep(1000);
		}
		printf("Character sent is: %c\n", message[i]);
		i++;
	}
}
int	main(int argc, char **argv)
{
	int	bits;

	struct sigaction sa;
	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
	{
		printf("Usage: %s [server_pid] [message]\n", argv[0]);
		exit(1);
	}
	global_argv = argv;
	printf("Gargv[1](server pid entered) = %s\n", global_argv[1]);
	printf("Gargv[2](String to be sent) = %s\n", global_argv[2]);
	printf("clientpid: %d\n", getpid());
	if (global_argv[2][0] && global_argv[2][0] != '\0')
	{
		printf("First chara bits starting to send\n");
		printf("Gargv[2][0](First character) = %c\n", global_argv[2][0]);
		bits = 7;
		while (bits >= 0)
		{
			if (global_argv[2][0] & (1 << bits)){
				kill(ft_atoi(global_argv[1]), SIGUSR1);
				printf("bit = 1 sent\n");}
			else{
				kill(ft_atoi(global_argv[1]), SIGUSR2);
				printf("bit = 0 sent\n");}
			bits--;	
			usleep(1000);
		}
	}
	while(1)
		sleep(1);
	return (0);
}