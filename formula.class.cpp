/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:03:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/06/02 15:09:30 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

Formula::Formula(int type, Fact *fact1, Fact *fact2, int relation)
{
	this->type = type;
	this->fact1 = fact1;
	this->fact2 = fact2;
	this->relation = relation;
}

Formula::~Formula(void)
{
	return ;
}

e_status	Formula::not_operator(e_status status1, e_status status2)
{
	(void)status2;

	if (status1 == F_FALSE)
		return F_TRUE;
	else if (status1 == F_TRUE)
		return F_FALSE;
	return F_UNKNOWN;
}

e_status	Formula::and_operator(e_status status1, e_status status2)
{	
	if (status1 == F_FALSE || status2 == F_FALSE)
		return F_FALSE;
	else if (status1 == F_TRUE && status2 == F_TRUE)
		return F_TRUE;
	return F_UNKNOWN;
}

e_status	Formula::or_operator(e_status status1, e_status status2)
{
	if (status1 == F_TRUE || status2 == F_TRUE)
		return F_TRUE;
	if (status1 == F_FALSE && status2 == F_FALSE)
		return F_FALSE;
	return F_UNKNOWN;
}

e_status	Formula::xor_operator(e_status status1, e_status status2)
{
	if ((status1 == F_TRUE && status2 == F_FALSE)
			|| (status1 == F_FALSE && status2 == F_TRUE))
		return F_TRUE;
	if ((status1 == F_FALSE && status2 == F_FALSE)
			|| (status1 == F_TRUE && status2 == F_TRUE))
		return F_FALSE;
	return F_UNKNOWN;
}

e_status (*Formula::tab_func[NB_OPERATOR])(e_status, e_status) =
{
	Formula::not_operator,
	Formula::xor_operator,
	Formula::or_operator,
	Formula::and_operator
};

e_ret_type	Formula::set_status(e_status status, bool testing)
{
	if ((this->status > 1 && status < 0)
			|| (this->status < 0 && status > 1))
	{
		if (!testing)
			error_n_exit("Contradiction in the facts...\n");
		else
			return ERROR;
	}
	if (this->status != PENDING && status == UNKNOWN)
		return NON_ACTUALISED;
	this->status = static_cast<e_status>(status + testing);
	return ACTUALISED;
}

e_status	Formula::get_status(void)
{
	return this->status;
}

e_ret_type	Formula::compute_status(bool testing)
{
	e_status	status2 = F_TRUE;
	e_status	prev_status = this->status;
	e_ret_type	ret = NON_ACTUALISED;

	ret = this->fact1->compute_status(testing);
	if (this->fact2 != nullptr)
	{
		ret |= this->fact2->compute_status(testing);
		if (ret & ERROR)
			return ERROR;
		status2 = this->fact2->get_status();
	}

	if (this->set_status(tab_func[this->relation](this->fact1->get_status(), status2)) == ERROR)
		return ERROR;
	if (this->get_status() != prev_status)
		return ACTUALISED;
	return ret;
	//std::cout << "Formula status: " << this->get_status() << std::endl;
}

std::ostream & operator<<(std::ostream & o, const Formula & formula)
{
	o << "Fact1: " << *(formula.fact1) << std::endl << " Fact2: " << std::endl << *(formula.fact2) << std::endl << "Relation: " << formula.relation << std::endl;
	return o;
}
