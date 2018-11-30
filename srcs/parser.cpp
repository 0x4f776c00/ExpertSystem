/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:00:54 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/30 06:54:59 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

static void		get_queries(std::vector <std::vector <Token>> :: iterator line,
		Hub *hub)
{
	std::vector <Token> :: iterator i = (*line).begin();
	i++;
	for (; i != (*line).end(); i++)
	{
		if ((*i).type != FACT)
			error_n_exit("Non factual query");
		hub->facts[(*i).symbol - 'A'].used = true;
		hub->queries += (*i).symbol;
	}
}

static void		fact_set_truth(char symbol, int status, Hub *hub)
{
	for (std::vector <Fact> :: iterator i = (*hub).facts.begin();
			i != (*hub).facts.end(); i++)
	{
		if ((*i).symbol == symbol)
		{
			if ((*i).set == true)
				error_n_exit("Fact's truth set twice");
			(*i).set = true;
			(*i).used = true;
			(*i).status = status;
			return ;
		}
	}
}

static void		get_truth(std::vector <std::vector <Token>> :: iterator line,
		Hub *hub)
{
	int	status;
	std::vector <Token> :: iterator i = (*line).begin();
	i++;

	for (; i != (*line).end(); i++)
	{
		status = F_TRUE;
		if ((*i).symbol == '!')
		{
			status = F_FALSE;
			i++;
			if (i == (*line).end())
				error_n_exit("The void can't be false");
		}
		if ((*i).type != FACT)
			error_n_exit("Non-factual truth attribution");
		fact_set_truth((*i).symbol, status, hub);
	}
}

static int		get_end_parenthesis(Hub *hub, std::vector <Token> line,
		int i, int end)
{
	i++;
	while (line[i].symbol != ')')
	{
		if (line[i].symbol == '(')
			i = get_end_parenthesis(hub, line, i, end);
		i++;
		if (i >= end || i == 0)
			return (-1);
	}
	return (i);
}

static Fact	*get_formula(Hub *hub, std::vector <Token> line, int begin, int end)
{
	(void)hub;
	int	index = -1;
	int	priority = -1;

	for (int i = begin; i < end; i++)
	{
		if (line[i].symbol == ')')
			error_n_exit("Parenthesis don't match1");
		if (line[i].symbol == '(')
		{
			int tmp = i;
			if ((i = get_end_parenthesis(hub, line, i, end)) == -1)
				error_n_exit("Parenthesis don't match2");
			if (i >= end - 1 && tmp == begin)
			{
				i = begin;
				begin++;
				end--;
				continue ;
			}
			continue ;
		}
		if (line[i].operator_type > priority)
		{
			index = i;
			priority = line[i].operator_type;
		}
		if (line[i].type == FACT && i + 1 < end
				&& line[i + 1].operator_type == NOT)
			error_n_exit("Error in formula");
	}
	if (begin == end - 1)
	{
		hub->facts[line[begin].symbol - 'A'].used = true;
		return &hub->facts[line[begin].symbol - 'A'];
	}
	if (priority == -1)
		error_n_exit("Error in formula");
	if (priority == NOT)
		return new Formula(1, get_formula(hub, line, index + 1, end),
				nullptr, priority);
	return new Formula(1, get_formula(hub, line, begin, index),
			get_formula(hub, line, index + 1, end), priority);
}

static void		get_axioms(std::vector <Token> line, Hub *hub)
{
	(void)hub;
	int relation = -1;
	for (size_t i = 0; i < line.size(); i++)
	{
		if (line[i].type == RELATION)
		{
			relation = static_cast<int>(i);
			break ;
		}
	}
	if (relation == -1)
		error_n_exit("Missing relation");
	bool bicond = (line[relation].symbol == '=') ? 1 : 0;
	Axiom axiom(get_formula(hub, line, 0, relation),
			get_formula(hub, line, relation + 1, line.size()), bicond);
	hub->axioms.push_back(axiom);
}

void			parse_system(std::vector <std::vector <Token>> tokens, Hub *hub)
{
	for (std::vector <std::vector <Token>> :: iterator i = tokens.begin();
			i != tokens.end(); ++i)
	{
		if ((*(*i).begin()).type == QUERY)
			get_queries(i, hub);
		else if ((*(*i).begin()).type == TRUTH)
			get_truth(i, hub);
		else
			get_axioms(*i, hub);
	}
}
