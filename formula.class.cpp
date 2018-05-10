/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:03:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/10 11:19:44 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

Formula::Formula(Facts *fact1, Facts *fact2, int relation)
{
	this->fact1 = fact1;
	this->fact2 = fact2;
	this->relation = relation;
}

Formula::~Formula(void)
{
	return ;
}

e_status	Formula::not_operator(Facts fact1, Facts fact2)
{
	e_status	status1 = fact1.get_status();
	
	(void)fact2;
	if (status1 == F_FALSE)
		return F_TRUE;
	else if (status1 == F_TRUE)
		return F_FALSE;
	return F_UNKNOWN;
}

e_status	Formula::and_operator(Facts fact1, Facts fact2)
{
	e_status	status1 = fact1.get_status();
	e_status	status2 = fact2.get_status();
	
	if (status1 == F_FALSE || status2 == F_FALSE)
		return F_FALSE;
	else if (status1 == F_TRUE && status2 == F_TRUE)
		return F_TRUE;
	return F_UNKNOWN;
}

e_status	Formula::or_operator(Facts fact1, Facts fact2)
{
	e_status	status1 = fact1.get_status();
	e_status	status2 = fact2.get_status();

	if (status1 == F_TRUE || status2 == F_TRUE)
		return F_TRUE;
	if (status1 == F_FALSE && status2 == F_FALSE)
		return F_FALSE;
	return F_UNKNOWN;
}

e_status	Formula::xor_operator(Facts fact1, Facts fact2)
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

	e_status (*Formula::tab_func[NB_OPERATOR])(Facts, Facts) =
	{
		Formula::xor_operator,
		Formula::or_operator,
		Formula::and_operator,
		Formula::not_operator
	};

void	Formula::compute_status()
{
	this->set_status(tab_func[this->relation](*this->fact1, *this->fact2));
}

std::ostream & operator<<(std::ostream & o, const Formula & formula)
{
	o << "Fact1: " << *(formula.fact1) << std::endl << " Fact2: " << std::endl << *(formula.fact2) << std::endl << "Relation: " << formula.relation << std::endl;
	return o;
}
