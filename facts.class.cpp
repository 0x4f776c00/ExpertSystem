/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   facts.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:38:16 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/01 16:54:14 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

Facts::Facts(const char symbol) : symbol(symbol)
{
	this->_status = F_PENDING;
}

Facts::Facts(void) : symbol('\0')
{
	this->_status = F_PENDING;
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
	if ((this->_status == F_TRUE && status == F_FALSE)
			|| (this->_status == F_FALSE && status == F_TRUE))
		return ; //apocalypse();
	if (this->_status != F_PENDING && status == F_UNKNOWN)
		return ;
	this->_status = status;
}
