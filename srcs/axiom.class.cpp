/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axiom.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:31:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/01 02:23:11 by bcozic           ###   ########.fr       */
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

	ret = this->fact1->compute_status(testing);
	if (this->biconditional)
		ret |= this->fact2->compute_status(testing);
	status1 = this->fact1->get_status(testing);
	status2 = this->fact2->get_status(testing);
	if (this->biconditional && ((status1 <= S_FALSE && status2 == S_TRUE)
			|| (status2 <= S_FALSE && status1 == S_TRUE)))
	{
		this->fact1->set_s_to_pending();
		this->fact2->set_s_to_pending();
		status1 = this->fact1->get_status(testing);
		status2 = this->fact2->get_status(testing);
	}
	if ((this->biconditional && (status1 == F_FALSE
			|| status1 == F_FALSE + testing
			|| (status1 <= S_FALSE && status2 != F_TRUE
			&& status2 != F_FALSE))) || status1 == F_TRUE
			|| status1 == F_TRUE + testing || (status1 == S_TRUE
			&& (!this->biconditional || (status2 != F_TRUE
			&& status2 != F_FALSE))))
	{
		status2 = this->fact2->get_status(testing);
		ret |= this->fact2->set_status(status1, testing);
		if (status2 != this->fact2->get_status(testing))
			ret |= ACTUALISED;
		ret |= this->fact2->compute_propagate_status(testing);
	}
	status2 = this->fact2->get_status(testing);
	if (this->biconditional && (status2 == F_TRUE
			|| status2 == F_TRUE + testing || status2 == S_TRUE
			|| status2 == F_FALSE || status2 == F_FALSE + testing
			|| status2 <= S_FALSE))
	{
		ret |= this->fact1->set_status(status2, testing);
		if (status1 != this->fact1->get_status(testing))
			ret |= ACTUALISED;
		ret |= this->fact1->compute_propagate_status(testing);
	}
	if (ret & SET_PENDING && !(ret & ERROR))
	{
		this->fact1->set_s_to_pending();
		this->fact2->set_s_to_pending();
		return ACTUALISED;
	}
	return ret;
}

void	Axiom::clean(void)
{
	this->fact1->clean();
	this->fact2->clean();
}
