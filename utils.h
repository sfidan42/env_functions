#include <stdio.h>
#include "libft/libft.h"

typedef struct s_env
{
	t_list	*exp;
	t_list	*env;
}			t_env;

extern t_env	g_env;

t_env	ft_env_cpy(char **aw);
t_list	*ft_env_add(t_list *lst, char *expr);
char	*ft_env_get(t_list *lst, char *name);
t_list	*ft_env_del(t_list *lst, char *name);
