/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:09:34 by sadettin          #+#    #+#             */
/*   Updated: 2023/04/05 17:27:53 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_env	ft_env_cpy(char **aw)
{
	t_env	new_env;

	new_env.env = NULL;
	new_env.exp = NULL;
	while (*aw)
		ft_lstadd_back(&new_env.env, ft_lstnew(ft_strdup(*aw++)));
	return (new_env);
}

char	*ft_env_get(t_list *lst, char *name)
{
	void	*loc;
	t_list	*aux;

	aux = lst;
	while (aux)
	{
		loc = ft_strchr(aux->content, '=');
		if (!ft_strncmp(aux->content, name, loc - aux->content))
			return (loc + 1);
		aux = aux->next;
	}
	return (NULL);
}

t_list	*ft_env_del(t_list *lst, char *name)
{
	void	*loc;
	t_list	*aux;

	aux = lst;
	while (aux)
	{
		loc = ft_strchr(aux->content, '=');
		if (!ft_strncmp(aux->content, name, loc - aux->content))
		{
			aux->content = "";
			break ;
		}
		aux = aux->next;
	}
	return (lst);	
}

t_list	*ft_env_add(t_list *lst, char *expr)
{
	void	*loc;
	t_list	*aux;

	aux = lst;
	while (aux)
	{
		loc = ft_strchr(aux->content, '=');
		if (!ft_strncmp(aux->content, expr, loc - aux->content))
		{
			aux->content = expr;
			return (lst);
		}
		aux = aux->next;
	}
	ft_lstadd_back(&lst, ft_lstnew(expr));
	return (lst);
}

