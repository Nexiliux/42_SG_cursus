/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchow <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:41:21 by wchow             #+#    #+#             */
/*   Updated: 2023/09/13 21:20:23 by wchow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTLIB_H
# define PRINTLIB_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *, ...)
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

#endif
