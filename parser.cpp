/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:00:54 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/08 19:28:07 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

static void		aff_token_list(std::vector <Token> token_vector)
{
	std::vector <Token> :: iterator i;
	for (i = token_vector.begin(); i != token_vector.end(); ++i)
		std::cout << *i << '\n';
}

void			parse_system(std::vector <Token> token_vector, Hub *hub)
{
	(void)hub;
	/// In a loop ?//////////////////////////////////////////////////////////
	//get_axioms() --> Get axioms and facts (add to fact_list and axiom_list)
	//get_truths() --> Set the facts status
	//get_queries() -> Fill the queries_list / set the wanted status of a fact
	//////////////////////////////////////////////////////////////////////////
	aff_token_list(token_vector);
}