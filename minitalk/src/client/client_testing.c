#include "../../libft/libft.h"
#include "../../printf/includes/ft_printf.h"
#include "../../minitalk.h"

int	main(int argc, char **argv)
{
	if (argc == 1 || argc > 2){
	char	*str;
	str = ft_strdup("Client libft/printf working");
	ft_printf("%s", str);
	return (0);
	}
	else
	{
		ft_printf("%s", argv[1]);
	}
	return (0);
	
}