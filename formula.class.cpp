/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:03:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/01 15:21:17 by bcozic           ###   ########.fr       */
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