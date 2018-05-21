/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:31:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/21 15:09:11 by justasze         ###   ########.fr       */
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

bool	Axiom::compute_axiom()
{
	bool	ret = false;

	std::cout << this->fact1 << std::endl;
	ret = this->fact1->compute_status();
	std::cout << "AXIOM FACT1 STATUS: " << this->fact1->get_status() << "\n";
	if (this->biconditional || this->fact1->get_status() == F_TRUE)
		this->fact2->set_status(this->fact1->get_status());

	return ret;
	// TODO: if fact2 is a formula, create a function
	// to propagate its status among itself
}
