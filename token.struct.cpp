/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.struct.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:11:30 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/08 17:58:22 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

Token::Token(char symbol, e_token_type type)
{
	this->symbol = symbol;
	this->type = type;
}

Token::~Token()
{
	return ;
}

std::ostream & operator<<(std::ostream & o, const Token & token)
{
    o << "Symbol: '" << token.symbol << "' Type: " << static_cast<int>(token.type) << std::endl;
    return o;
}