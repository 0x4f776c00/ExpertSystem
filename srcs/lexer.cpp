/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:22:34 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/30 06:55:01 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

static int		isoperator(char it, int *operator_type)
{
	switch (it)
	{
		case '^' :
			*operator_type = XOR;
			return 1;
		case '|' :
			*operator_type = OR;
			return 1;
		case '+' :
			*operator_type = AND;
			return 1;
		case '!' :
			*operator_type = NOT;
			return 1;
		case '(' :
			return 1;
		case ')' :
			return 1;
		default :
			return 0;
	}
}

static e_token_type	check_symbol(std::string::iterator *it, int *operator_type)
{
	if (isupper(**it))
		return FACT;
	if (isoperator(**it, operator_type))
		return OPERATOR;
	else if ((**it == '=' && *(*it + 1) == '>')
			|| (**it == '<' && *(*it + 1) == '=' && *(*it + 2) == '>'))
	{
		*it = *it + 1;
		return RELATION;
	}
	return INVALID;
}

static void					open_stream(char *file_name, std::ifstream *ifs)
{
	(*ifs).exceptions(std::ifstream::failbit);

	try
	{
		(*ifs).open(file_name);
	}
	catch (std::ios_base::failure& e)
	{
		std::srand(std::time(NULL));
		if (std::rand() % 2 == 0)
 			std::cerr << "Error while opening file" << std::endl;
		else
		 	std::cerr << "Error when opening file" << std::endl;	
		exit(EXIT_FAILURE);
	}
}

static std::vector <std::vector <Token>>	tokenize(std::ifstream & ifs)
{
	std::string							line;
	std::vector <std::vector <Token>>	tokens;
	e_token_type						type;

	while (std::getline(ifs, line))
	{
		std::vector <Token>	token_vector;
		std::string::iterator it = line.begin();
		if (*line.begin() == '=' || *line.begin() == '?')
		{
			Token ret_token(*it, (*line.begin() == '=') ? TRUTH : QUERY, -1);
			token_vector.push_back(ret_token);
			it++;
		}
		for (; it!=line.end(); ++it)
		{
			int	operator_type = -1;
			if (isspace(*it))
				continue;
			else if (*it == '#')
				break;
			else if ((type = check_symbol(&it, &operator_type)) == INVALID)
			{
				ifs.close();
				error_n_exit("Bad file format");
			}
			Token ret_token(*it, type, operator_type);
			token_vector.push_back(ret_token);
			if (*it == '=')
				it++;
			continue;
		}
		if (token_vector.size() != 0)
			tokens.push_back(token_vector);
	}
	return tokens;
}

void						get_system(Hub *hub, char *file_name)
{
	std::ifstream ifs;
	open_stream(file_name, &ifs);
	parse_system(tokenize(ifs), hub);
	ifs.close();
}
