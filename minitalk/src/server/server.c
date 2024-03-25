#include "../../libft/libft.h"
#include "../../printf/includes/ft_printf.h"
#include "../../minitalk.h"

/*void	sig_handler(int	sig)
{

}*/

int	main()
{
	/*struct sigaction sa;
	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);*/

	ft_printf("Server PID: %d\n", getpid());
	return (0);
}