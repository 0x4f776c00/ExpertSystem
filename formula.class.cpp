/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:03:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/19 15:02:27 by justasze         ###   ########.fr       */
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
	Formula::xor_operator,
	Formula::or_operator,
	Formula::and_operator,
	Formula::not_operator
};

void		Formula::set_status(e_status status)
{
	if ((this->status == F_TRUE && status == F_FALSE)
			|| (this->status == F_FALSE && status == F_TRUE))
		error_n_exit("Contradiction in the facts...\n");
	if (this->status != F_PENDING && status == F_UNKNOWN)
		return ;
	this->status = status;
}

e_status	Formula::get_status(void)
{
	return this->status;
}

void	Formula::compute_status()
{
	// std::cout << "I AM A FORMULA:\n";
	// std::cout << this->relation << std::endl;
	// this->fact1->compute_status();
	// if (this->fact2 != nullptr)
	// 	this->fact2->compute_status();
	// else
	// 	std::cout << "NOT formula\n";
	e_status status2 = F_TRUE;
	this->fact1->compute_status();
	if (this->fact2 != nullptr)
	{
		this->fact2->compute_status();
		status2 = this->fact2->get_status();
	}

	this->set_status(tab_func[this->relation](this->fact1->get_status(), status2));
	std::cout << "Formula status: " << this->get_status() << std::endl;
}

std::ostream & operator<<(std::ostream & o, const Formula & formula)
{
	o << "Fact1: " << *(formula.fact1) << std::endl << " Fact2: " << std::endl << *(formula.fact2) << std::endl << "Relation: " << formula.relation << std::endl;
	return o;
}
