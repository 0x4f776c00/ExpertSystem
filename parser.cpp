/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:00:54 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/12 17:27:07 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

static void		aff_token_list(std::vector <std::vector <Token>> tokens)
{
	std::vector <std::vector <Token>> :: iterator line;
	for (line = tokens.begin(); line != tokens.end(); ++line)
	{
		for (std::vector <Token> :: iterator i = (*line).begin(); i != (*line).end(); ++i)
		{
			std::cout << *i << '\n';
		}
		std::cout << "end line\n";
	}
}

static int		fact_queried(char symbol, Hub *hub)
{
	int	ret = 0;
	for (std::list <Facts> :: iterator i = (*hub).facts.begin(); i != (*hub).facts.end(); i++)
	{
		if ((*i).symbol == symbol)
		{
			(*i).queried = true;
			ret = 1;
			break ;
		}
	}
	return (ret);
}

static void		get_queries(std::vector <std::vector <Token>> :: iterator line, Hub *hub)
{
	std::vector <Token> :: iterator i = (*line).begin();
	i++;
	for (; i != (*line).end(); i++)
	{
		if ((*i).type != FACT || !fact_queried((*i).symbol, hub))
			error_n_exit("Querying an undefined fact");
	}
}

static void		fact_set_true(char symbol, Hub *hub)
{
	for (std::list <Facts> :: iterator i = (*hub).facts.begin(); i != (*hub).facts.end(); i++)
	{
		if ((*i).symbol == symbol)
		{
			(*i).set_status(F_TRUE);
			return ;
		}
	}
	Facts fact(symbol);
	fact.set_status(F_TRUE);
	(*hub).facts.push_back(fact);
}

static void		get_truth(std::vector <std::vector <Token>> :: iterator line, Hub *hub)
{
	std::vector <Token> :: iterator i = (*line).begin();
	i++;
	for (; i != (*line).end(); i++)
	{
		if ((*i).type != FACT)
			error_n_exit(" an undefined fact");
		fact_set_true((*i).symbol, hub);
	}
}

void			parse_system(std::vector <std::vector <Token>> tokens, Hub *hub)
{
	for (std::vector <std::vector <Token>> :: iterator i = tokens.begin(); i != tokens.end(); ++i)
	{
		if ((*(*i).begin()).type == QUERY)
			get_queries(i, hub);
		else if ((*(*i).begin()).type == TRUTH)
			get_truth(i, hub);
		else
			get_axioms(i, hub);
	}
	aff_token_list(tokens);
}