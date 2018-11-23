/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:03:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/23 17:28:01 by bcozic           ###   ########.fr       */
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
	return UNKNOWN;
}

e_status	Formula::and_operator(e_status status1, e_status status2)
{	
	if (status1 == F_FALSE || status2 == F_FALSE)
		return F_FALSE;
	else if (status1 == F_TRUE && status2 == F_TRUE)
		return F_TRUE;
	return UNKNOWN;
}

e_status	Formula::or_operator(e_status status1, e_status status2)
{
	if (status1 == F_TRUE || status2 == F_TRUE)
		return F_TRUE;
	if (status1 == F_FALSE && status2 == F_FALSE)
		return F_FALSE;
	return UNKNOWN;
}

e_status	Formula::xor_operator(e_status status1, e_status status2)
{
	if ((status1 == F_TRUE && status2 == F_FALSE)
			|| (status1 == F_FALSE && status2 == F_TRUE))
		return F_TRUE;
	if ((status1 == F_FALSE && status2 == F_FALSE)
			|| (status1 == F_TRUE && status2 == F_TRUE))
		return F_FALSE;
	return UNKNOWN;
}

e_status (*Formula::tab_operators[NB_OPERATOR])(e_status, e_status) =
{
	Formula::not_operator,
	Formula::xor_operator,
	Formula::or_operator,
	Formula::and_operator
};

e_ret_type	Formula::not_propagate(Formula &formula, bool testing)
{
	e_ret_type ret = NON_ACTUALISED;
std::cout << "not propagate" << std::endl;

	if (formula.status == F_TRUE)
		ret = formula.fact1->set_status(F_FALSE, testing);
	else if (formula.status == F_FALSE)
		ret = formula.fact1->set_status(F_TRUE, testing);
	else if (formula.status == T_TRUE)
		ret = formula.fact1->set_status(T_FALSE, testing);
	else if (formula.status == T_FALSE)
		ret = formula.fact1->set_status(T_TRUE, testing);

	return ret;
}

e_ret_type	Formula::and_propagate(Formula &formula, bool testing)
{
	e_ret_type ret = NON_ACTUALISED;
	e_ret_type ret2 = NON_ACTUALISED;
std::cout << "and propagate" << std::endl;
	if (formula.status == F_TRUE)
	{
		ret = formula.fact1->set_status(F_TRUE, testing);
		ret2 = formula.fact2->set_status(F_TRUE, testing);
	}
	else if (formula.status == T_TRUE)
	{
		ret = formula.fact1->set_status(T_TRUE, testing);
		ret2 = formula.fact2->set_status(T_TRUE, testing);
	}
	else if (formula.status == F_FALSE)
	{
		if (formula.fact1->get_state() == F_TRUE && formula.fact2->get_state() == F_TRUE)
			error_n_exit("Contradiction in the facts...\n");
	}
	if (ret == ERROR || ret2 == ERROR)
		return ERROR;
	if (ret == ACTUALISED || ret2 == ACTUALISED)
		return ACTUALISED;
	return NON_ACTUALISED;
}

e_ret_type	Formula::or_propagate(Formula &formula, bool testing)
{
	(void)testing;
	(void)formula;
	return NON_ACTUALISED;
}

e_ret_type	Formula::xor_propagate(Formula &formula, bool testing)
{
	(void)testing;
	(void)formula;
	return NON_ACTUALISED;
}

e_ret_type (*Formula::tab_propagate[NB_OPERATOR])(Formula&, bool) =
{
	Formula::not_propagate,
	Formula::xor_propagate,
	Formula::or_propagate,
	Formula::and_propagate
};

e_ret_type	Formula::propagate_status(bool testing)
{
	return tab_propagate[this->relation](*this, testing);
}

e_ret_type	Formula::set_status(e_status status, bool testing)
{
	std::cout << "set status formula" << std::endl;

	if ((this->status > 1 && status < 0)
			|| (this->status < 0 && status > 1))
	{
		if (!testing)
			error_n_exit("Contradiction in the facts...\n");
		else
			return ERROR;
	}
	if (status == UNKNOWN)
	{
		std::cout << "set status non_actualised" << std::endl;
		return NON_ACTUALISED;
	}
	this->status = static_cast<e_status>(status + testing);
	if (this->propagate_status(testing) == ERROR)
		return ERROR;
	std::cout << "set status actualised" << std::endl;
	return ACTUALISED;
}

e_status	Formula::get_state(void)
{
	return tab_operators[this->relation](this->fact1->get_status(), this->fact2->get_status());
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
		ret = static_cast<e_ret_type>(static_cast<int>(ret) | static_cast<int>(this->fact2->compute_status(testing)));
		if (ret & ERROR)
			return ERROR;
		status2 = this->fact2->get_status();
	}

	if (this->set_status(tab_operators[this->relation](this->fact1->get_status(), status2), testing) == ERROR)
		return ERROR;
	if (this->get_status() != prev_status)
		return ACTUALISED;
	return ret;
}

std::ostream & operator<<(std::ostream & o, const Formula & formula)
{
	o << "Fact1: " << *(formula.fact1) << std::endl << " Fact2: " << std::endl << *(formula.fact2) << std::endl << "Relation: " << formula.relation << std::endl;
	return o;
}
