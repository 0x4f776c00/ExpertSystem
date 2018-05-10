/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   facts.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:38:16 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/10 11:53:06 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

Facts::Facts(const char symbol) : symbol(symbol)
{
	this->_status = F_PENDING;
	this->queried = false;
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

void	Facts::compute_status()
{
	std::cout << "I AM A FACT\n";
	//this->set_status(tab_func[this->relation](*this->fact1, *this->fact2));
}

std::ostream & operator<<(std::ostream & o, const Facts & fact)
{
	o << "Symbol: " << fact.symbol << std::endl;
	return o;
}