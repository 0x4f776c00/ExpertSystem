/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.struct.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:11:30 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/02 16:26:49 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

Token::Token(char symbol)
{
	this->symbol = symbol;
	if (isupper(symbol))
		this->type = FACT;
	else if (symbol == '>' || symbol == '=')
		this->type = RELATION;
	else if (symbol == '\n')
		this->type = SEPARATOR;
	else
		this->type = OPERATOR;
}