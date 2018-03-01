/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   facts.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:38:16 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/01 15:03:17 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

Facts::Facts(const char symbol) : symbol(symbol)
{
	this->_status = PENDING;
}

Facts::~Facts(void)
{
	return ;
}

e_status	Facts::get_status(void)
{
	return (this->_status);
}

void		Facts::set_status(e_status status)
{
	if ((this->_status == TRUE && status == FALSE)
			|| (this->_status == FALSE && status == TRUE))
		apocalypse();
	if (this->_status != PENDING && status == UNKNOW)
		return ;
	this->_status = status;
}
