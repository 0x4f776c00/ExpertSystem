/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:22:34 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/08 18:06:19 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

static int		isoperator(char it)
{
	if (it == '|' || it == '+' || it == '!' || it == '^' || it == '(' || it == ')')
		return 1;
	return 0;
}

static e_token_type	check_symbol(std::string::iterator it)
{
	if (isupper(*it))
		return FACT;
	if (isoperator(*it))
		return OPERATOR;
	else if ((*it == '=' && *(it + 1) == '>') || (*it == '<' && *(it + 1) == '=' && *(it + 2) == '>'))
	{
		it++;
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

static std::vector <Token>	tokenize(std::ifstream & ifs)
{
	std::string			line;
	std::vector <Token>	token_vector;
	e_token_type		type;
	while (std::getline(ifs, line))
	{
		std::string::iterator it = line.begin();
		if (*line.begin() == '=' || *line.begin() == '?')
		{
			Token ret_token(*it, (*line.begin() == '=') ? TRUTH : QUERY);
			token_vector.push_back(ret_token);
			it++;
		}
		for (; it!=line.end(); ++it)
		{
			if (isspace(*it))
				continue;
			else if (*it == '#')
				break;
			else if ((type = check_symbol(it)) == INVALID)
			{
				ifs.close();
				error_n_exit("Bad file format");
			}
			Token ret_token(*it, type);
			token_vector.push_back(ret_token);
			if (*it == '=')
				it++;
			continue;
		}
		if (token_vector.size() != 0 && token_vector.back().type != SEPARATOR)
		{
			Token ret_token(';', SEPARATOR);
			token_vector.push_back(ret_token);
		}
	}
	return token_vector;
}

static void					aff_token_list(std::vector <Token> token_vector, Hub *hub)
{
	(void) hub;
	std::vector <Token> :: iterator i;
	for (i = token_vector.begin(); i != token_vector.end(); ++i)
		std::cout << *i << '\n';
}

void						get_system(Hub *hub, char *file_name)
{
	std::ifstream ifs;
	open_stream(file_name, &ifs);
	aff_token_list(tokenize(ifs), hub);
	ifs.close();
}