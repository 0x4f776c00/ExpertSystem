/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:31:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/28 16:35:04 by bcozic           ###   ########.fr       */
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

int		Axiom::compute_axiom(int testing)
{
	int	ret;
	int	status_before;

	if ((ret = this->fact1->compute_status(testing)) == ERROR)
		return ret;
	if ((this->biconditional && (this->fact1->get_status(testing) == F_FALSE
			|| this->fact1->get_status(testing) == F_FALSE + testing))
			|| this->fact1->get_status(testing) == F_TRUE
			|| this->fact1->get_status(testing) == F_TRUE + testing)
	{
		status_before = this->fact2->get_status(testing);
		if (this->fact2->set_status(this->fact1->get_status(testing), testing) == ERROR)
			return ERROR;
		if (status_before != this->fact2->get_status(testing))
			ret |= ACTUALISED;
		ret |= this->fact2->compute_propagate_status(testing);
	}
	if (this->biconditional && (this->fact2->get_status(testing) == F_TRUE
			|| this->fact2->get_status(testing) == F_TRUE + testing
			|| this->fact2->get_status(testing) == F_FALSE
			|| this->fact2->get_status(testing) == F_FALSE + testing))
	{
		status_before = this->fact1->get_status(testing);
		if (this->fact1->set_status(this->fact2->get_status(testing), testing) == ERROR)
			return ERROR;
		if (status_before != this->fact1->get_status(testing))
			ret |= ACTUALISED;
		ret |= this->fact1->compute_propagate_status(testing);
	}
	return ret;
}

void	Axiom::clean(void)
{
	this->fact1->clean();
	this->fact2->clean();
}