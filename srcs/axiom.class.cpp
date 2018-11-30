/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:31:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/30 06:55:13 by bcozic           ###   ########.fr       */
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
	int	status1;
	int	status2;

	if ((ret = this->fact1->compute_status(testing)) == ERROR)
		return ret;
	status1 = this->fact1->get_status(testing);
	if ((this->biconditional && (status1 == F_FALSE
			|| status1 == F_FALSE + testing || status1 == S_FALSE))
			|| status1 == F_TRUE || status1 == F_TRUE + testing
			|| status1 == S_TRUE)
	{
		status2 = this->fact2->get_status(testing);
		if (this->fact2->set_status(status1, testing) == ERROR)
			return ERROR;
		if (status2 != this->fact2->get_status(testing))
			ret |= ACTUALISED;
		ret |= this->fact2->compute_propagate_status(testing);
	}
	status2 = this->fact2->get_status(testing);
	if (this->biconditional && (status2 == F_TRUE
			|| status2 == F_TRUE + testing || status2 == S_TRUE
			|| status2 == F_FALSE || status2 == F_FALSE + testing
			|| status2 == S_FALSE))
	{
		if (this->fact1->set_status(status2, testing) == ERROR)
			return ERROR;
		if (status1 != this->fact1->get_status(testing))
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
