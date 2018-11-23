/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:03:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/23 19:08:10 by bcozic           ###   ########.fr       */
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
	else if (status1 == T_FALSE)
		return T_TRUE;
	else if (status1 == T_TRUE)
		return T_FALSE;
	return UNKNOWN;
}

e_status	Formula::and_operator(e_status status1, e_status status2)
{	
	if (status1 == F_FALSE || status2 == F_FALSE)
		return F_FALSE;
	else if (status1 == F_TRUE && status2 == F_TRUE)
		return F_TRUE;
	else if (status1 <= T_FALSE || status2 <= T_FALSE)
		return T_FALSE;
	else if (status1 >= F_TRUE && status2 >= F_TRUE)
		return T_TRUE;
	return UNKNOWN;
}

e_status	Formula::or_operator(e_status status1, e_status status2)
{
	if (status1 == F_TRUE || status2 == F_TRUE)
		return F_TRUE;
	else if (status1 == F_FALSE && status2 == F_FALSE)
		return F_FALSE;
	else if (status1 >= F_TRUE || status2 >= F_TRUE)
		return T_TRUE;
	else if (status1 <= T_FALSE && status2 <= T_FALSE)
		return T_FALSE;
	return UNKNOWN;
}

e_status	Formula::xor_operator(e_status status1, e_status status2)
{
	if ((status1 == F_TRUE && status2 == F_FALSE)
			|| (status1 == F_FALSE && status2 == F_TRUE))
		return F_TRUE;
	else if ((status1 == F_FALSE && status2 == F_FALSE)
			|| (status1 == F_TRUE && status2 == F_TRUE))
		return F_FALSE;
	else if ((status1 >= F_TRUE && status2 <= T_FALSE)
			|| (status1 <= T_FALSE && status2 >= F_TRUE))
		return T_TRUE;
	else if ((status1 <= T_FALSE && status2 <= T_FALSE)
			|| (status1 >= F_TRUE && status2 >= F_TRUE))
		return T_FALSE;
	return UNKNOWN;
}

e_status (*Formula::tab_operators[NB_OPERATOR])(e_status, e_status) =
{
	Formula::not_operator,
	Formula::xor_operator,
	Formula::or_operator,
	Formula::and_operator
};

int	Formula::not_propagate(Formula &formula, bool testing)
{
	int ret = NON_ACTUALISED;

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

int	Formula::and_propagate(Formula &formula, bool testing)
{
	int ret = NON_ACTUALISED;
	int ret2 = NON_ACTUALISED;
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
		if (formula.fact1->get_status() == F_TRUE && formula.fact2->get_status() == F_TRUE)
			error_n_exit("Contradiction in the facts...\n");
	}
	if (ret == ERROR || ret2 == ERROR)
		return ERROR;
	if (ret == ACTUALISED || ret2 == ACTUALISED)
		return ACTUALISED;
	return NON_ACTUALISED;
}

int	Formula::or_propagate(Formula &formula, bool testing)
{
	(void)testing;
	(void)formula;
	return NON_ACTUALISED;
}

int	Formula::xor_propagate(Formula &formula, bool testing)
{
	(void)testing;
	(void)formula;
	return NON_ACTUALISED;
}

int (*Formula::tab_propagate[NB_OPERATOR])(Formula&, bool) =
{
	Formula::not_propagate,
	Formula::xor_propagate,
	Formula::or_propagate,
	Formula::and_propagate
};

int	Formula::propagate_status(bool testing)
{
	return tab_propagate[this->relation](*this, testing);
}

int	Formula::set_status(e_status status, bool testing)
{
	if ((this->status >= T_TRUE && status <= F_FALSE)
			|| (this->status <= F_FALSE && status >= T_TRUE))
	{
		if (!testing)
			error_n_exit("Contradiction in the facts...\n");
		else
			return ERROR;
	}
	if (status == UNKNOWN)
	{
		return NON_ACTUALISED;
	}
	this->status = static_cast<e_status>(status + testing);
	if (this->propagate_status(testing) == ERROR)
		return ERROR;
	return ACTUALISED;
}

e_status	Formula::get_status(void)
{
	if (this->fact2)
		return tab_operators[this->relation](this->fact1->get_status(), this->fact2->get_status());
	return this->status;
}

int	Formula::compute_status(bool testing)
{
	e_status	status2 = F_TRUE;
	e_status	prev_status = this->get_status();
	int	ret = NON_ACTUALISED;

	ret = this->fact1->compute_status(testing);
	if (this->fact2 != nullptr)
	{
		ret = static_cast<int>(static_cast<int>(ret) | static_cast<int>(this->fact2->compute_status(testing)));
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
