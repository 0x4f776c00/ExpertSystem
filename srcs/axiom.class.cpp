/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:31:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/27 16:51:25 by bcozic           ###   ########.fr       */
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

int	Axiom::compute_axiom(bool testing)
{
	int	ret;
	e_status	status_before;

	ret = this->fact1->compute_status(testing);
	if (this->biconditional || this->fact1->get_status() >= F_TRUE)
	{
		status_before = this->fact2->get_status();
		if (this->fact2->set_status(this->fact1->get_status(), testing) == ERROR)
			return ERROR;
		if (status_before != this->fact2->get_status())
			ret |= ACTUALISED;
	}
	return ret;
}
