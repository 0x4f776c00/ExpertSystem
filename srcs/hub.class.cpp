/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:06:32 by justasze          #+#    #+#             */
/*   Updated: 2018/11/27 19:03:02 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

Hub::Hub(void)
{
	this->actualized = false;
	this->solved = false;
}

Hub::~Hub(void)
{
	this->facts.clear();
	this->axioms.clear();
}

void	Hub::add_axiom(Axiom axiom)
{
	this->axioms.push_front(axiom);
}

bool	Hub::has_been_actualized(void)
{
	return this->actualized;
}

bool	Hub::is_solved(void)
{
	return this->solved;
}

void	Hub::set_actualized_status(bool status)
{
	this->actualized = status;
}

void	Hub::set_solved(void)
{
	this->solved = true;
}
