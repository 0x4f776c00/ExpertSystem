/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:31:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/23 15:40:53 by justasze         ###   ########.fr       */
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
	bool		ret;
	e_status	status_before;

	ret = this->fact1->compute_status(testing);
	if (this->biconditional || this->fact1->get_status() == F_TRUE)
	{
		status_before = this->fact2->get_status();
		this->fact2->set_status(this->fact1->get_status(), testing);
		if (status_before != this->fact2->get_status())
			ret = true;
	}
	return ret;
}
