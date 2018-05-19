/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:31:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/19 10:55:39 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

Axiom::Axiom(Fact *f1, Fact *f2, bool bicond)
{
	this->fact1 = f1;
	this->fact2 = f2;
	this->biconditional = bicond;
}

Axiom::~Axiom(void)
{
	return ;
}
