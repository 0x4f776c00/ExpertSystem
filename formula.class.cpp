/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:03:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/19 12:45:08 by bcozic           ###   ########.fr       */
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

e_status	Formula::not_operator(Fact fact1, Fact fact2)
{
	e_status	status1 = fact1.get_status();
	
	(void)fact2;
	if (status1 == F_FALSE)
		return F_TRUE;
	else if (status1 == F_TRUE)
		return F_FALSE;
	return F_UNKNOWN;
}

e_status	Formula::and_operator(Fact fact1, Fact fact2)
{
	e_status	status1 = fact1.get_status();
	e_status	status2 = fact2.get_status();
	
	if (status1 == F_FALSE || status2 == F_FALSE)
		return F_FALSE;
	else if (status1 == F_TRUE && status2 == F_TRUE)
		return F_TRUE;
	return F_UNKNOWN;
}

e_status	Formula::or_operator(Fact fact1, Fact fact2)
{
	e_status	status1 = fact1.get_status();
	e_status	status2 = fact2.get_status();

	if (status1 == F_TRUE || status2 == F_TRUE)
		return F_TRUE;
	if (status1 == F_FALSE && status2 == F_FALSE)
		return F_FALSE;
	return F_UNKNOWN;
}

e_status	Formula::xor_operator(Fact fact1, Fact fact2)
{
	e_status	status1 = fact1.get_status();
	e_status	status2 = fact2.get_status();

	if ((status1 == F_TRUE && status2 == F_FALSE)
			|| (status1 == F_FALSE && status2 == F_TRUE))
		return F_TRUE;
	if ((status1 == F_FALSE && status2 == F_FALSE)
			|| (status1 == F_TRUE && status2 == F_TRUE))
		return F_FALSE;
	return F_UNKNOWN;
}

	e_status (*Formula::tab_func[NB_OPERATOR])(Fact, Fact) =
	{
		Formula::xor_operator,
		Formula::or_operator,
		Formula::and_operator,
		Formula::not_operator
	};

void	Formula::compute_status()
{
		std::cout << "I AM A FORMULA:\n";
		std::cout << this->relation << std::endl;
		this->fact1->compute_status();
		if (this->fact2 != nullptr)
			this->fact2->compute_status();
		else
			std::cout << "NOT formula\n";
	//this->set_status(tab_func[this->relation](*this->fact1, *this->fact2));
}

std::ostream & operator<<(std::ostream & o, const Formula & formula)
{
	o << "Fact1: " << *(formula.fact1) << std::endl << " Fact2: " << std::endl << *(formula.fact2) << std::endl << "Relation: " << formula.relation << std::endl;
	return o;
}
