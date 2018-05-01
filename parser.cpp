/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:00:54 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/01 17:05:25 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

// static void		aff_token_list(std::vector <std::vector <Token>> tokens)
// {
// 	std::vector <std::vector <Token>> :: iterator line;
// 	for (line = tokens.begin(); line != tokens.end(); ++line)
// 	{
// 		for (std::vector <Token> :: iterator i = (*line).begin(); i != (*line).end(); ++i)
// 		{
// 			std::cout << *i << '\n';
// 		}
// 		std::cout << "end line\n";
// 	}
// }

// static void		aff_token_line(std::vector <Token> tokens)
// {
// 	for (std::vector <Token> :: iterator i = tokens.begin(); i != tokens.end(); ++i)
// 	{
// 		std::cout << *i << '\n';
// 	}
// }

static int		fact_queried(char symbol, Hub *hub)
{
	int	ret = 0;
	for (std::vector <Facts> :: iterator i = (*hub).facts.begin(); i != (*hub).facts.end(); i++)
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
	for (std::vector <Facts> :: iterator i = (*hub).facts.begin(); i != (*hub).facts.end(); i++)
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

static Facts	get_formula(Hub *hub, std::vector <Token> line, int begin, int end)
{
	(void)hub;
	if (begin == end)
		return Facts(line[begin].symbol);
	return Facts(line[begin].symbol);
}

static void		get_axioms(std::vector <Token> line, Hub *hub)
{
	(void)hub;
	Facts fact = get_formula(hub, line, 0, 0);
	//aff_token_line(line);
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
			get_axioms(*i, hub);
	}
	//aff_token_list(tokens);
}