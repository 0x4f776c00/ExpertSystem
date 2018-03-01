/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:03:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/01 15:39:27 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

Formula::Formula(int relation, Facts *fact1, Facts *fact2)
{
	this->relation = relation;
	this->fact1 = fact1;
	this->fact2 = fact2;
}

Formula::~Formula(void)
{
	return ;
}

void	Formula::compute_status()
{
	this->set_status(tab_func[this->relation](this->fact1, this->fact2));
}

e_status	or_operator(Facts fact1, Facts fact2)
{
	e_status	status1 = fact1.get_status();
	e_status	status2 = fact2.get_status();

	if (status1 == F_TRUE || status2 == F_TRUE)
		return (F_TRUE);
	if (status1 == F_FALSE && status2 == F_FALSE)
		return (F_FALSE);
	return (F_UNKNOWN);
}

e_status	xor_operator(Facts fact1, Facts fact2)
{
	e_status	status1 = fact1.get_status();
	e_status	status2 = fact2.get_status();

	if ((status1 == F_TRUE && status2 == F_FALSE)
			|| (status1 == F_FALSE && status2 == F_TRUE))
		return (F_TRUE);
	if ((status1 == F_FALSE && status2 == F_FALSE)
			|| (status1 == F_TRUE && status2 == F_TRUE))
		return (F_FALSE);
	return (F_UNKNOWN)
}