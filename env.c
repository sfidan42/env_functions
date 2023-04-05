#include "utils.h"

t_env	g_env;

void	ft_export(char *name)
{
	void	*loc;
	t_list	*exp;

	exp = g_env.exp;
	while (exp)
	{
		loc = ft_strchr(exp->content, '=');
		if (!ft_strncmp(exp->content, name, loc - exp->content))
		{
			g_env.env = ft_env_add(g_env.env, exp->content);
			exp->content = "";
			break ;
		}
		exp = exp->next;
	}
}

void	ft_print_env(void *content)
{
	char	*str;

	str = content;
	printf("%s\n", str);
}

int	main(int ac, char **av, char **aw)
{
	(void)ac;
	(void)av;
	g_env = ft_env_cpy(aw);
	g_env.exp = ft_env_add(g_env.exp, "A=5");
	g_env.exp = ft_env_add(g_env.exp, "B=10");
	g_env.exp = ft_env_add(g_env.exp, "A=7");
	g_env.exp = ft_env_add(g_env.exp, "A=1001");
	
	ft_export("A");
	ft_export("B");
	ft_env_del(g_env.env, "A");
	//ft_lstiter(g_env.env, ft_print_env);
	//printf("%s\n",ft_env_get(g_env.env, "A")); // bu soldaki kod segfault veriyor!!
}
