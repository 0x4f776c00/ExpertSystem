/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:31:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/06/02 15:09:28 by bcozic           ###   ########.fr       */
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

bool	Axiom::compute_axiom(bool testing)
{
	bool	ret = false;

	ret = this->fact1->compute_status(bool testing);
	if (this->biconditional || this->fact1->get_status() == F_TRUE)
		this->fact2->set_status(this->fact1->get_status(), bool testing);

	return ret;
	// TODO: if fact2 is a formula, create a function
	// to propagate its status among itself
}
