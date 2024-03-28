#include "../../libft/libft.h"
#include "../../printf/includes/ft_printf.h"
#include "../../minitalk.h"

char	*result;

void	save_and_send(char c, int use)
{
	static char	*result = NULL;
	static int	i = 0;
	char	*temp;

	printf("SAS started\n");
	printf("c is: %c\n", c);
	if (!result && c && use == 1)
	{
		printf("1st if entered\n");
		result = ft_strdup(&c);
	}
	else if (result[i] && c && use == 1)
	{
		printf("2nd if entered\n");
		temp = ft_strjoin(result, &c);
		free(result);
		result = temp;
		i++;
	}
	if (use == 2)
	{
		printf("3rd if entered\n");
		ft_printf("%s\n", result);
		free(result);
		free(temp);
		result = NULL;
		i = 0;
	}
	printf("result is: %s\n", result);
	printf("SAS ended\n");
}

void	sig_handler(int	sig, siginfo_t *info, void *context)
{
	static int	bits = 0;
	static char	current_char = 0;

	(void)context;
	current_char <<= 1;
	if(sig == SIGUSR1)
		printf("Sig1 received\n");
	if(sig == SIGUSR2)
		printf("Sig2 received\n");
	if(sig == SIGUSR1)
		current_char |= 1;
	bits++;
	printf("bits is now = %d\n", bits);
	printf("current_char is now = %c\n", current_char);
	if (bits == 8 && current_char == '\0')
	{
		save_and_send(current_char, 2);
		bits = 0;
		current_char = 0;
	}
	else if (bits == 8)
	{
		printf("bits == 8 has entered\n");
		save_and_send(current_char, 1);
		bits = 0;
		current_char = 0;
		kill(info->si_pid, SIGUSR1);
		printf("client pid is: %d\n", info->si_pid);
		printf("SIGUSR1 sent to client\n");
	}
}

int	main()
{
	struct sigaction sa;
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