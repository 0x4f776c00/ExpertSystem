/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fact.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:38:16 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/10 16:59:43 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

Fact::Fact(int type, const char symbol) : type(type), symbol(symbol)
{
	this->_status = F_PENDING;
	this->queried = false;
}

Fact::Fact(void) : symbol('\0')
{
	this->_status = F_PENDING;
}


Fact::~Fact(void)
{
	return ;
}

e_status	Fact::get_status(void)
{
	return (this->_status);
}

void		Fact::set_status(e_status status)
{
	if ((this->_status == F_TRUE && status == F_FALSE)
			|| (this->_status == F_FALSE && status == F_TRUE))
		return ; //apocalypse();
	if (this->_status != F_PENDING && status == F_UNKNOWN)
		return ;
	this->_status = status;
}

void	Fact::compute_status()
{
	if (this->type == 1)
	{
		Formula test = *static_cast<Formula *>(this);
		test.compute_status();
	}
	else
	{
		std::cout << "I AM A FACT: " << this->symbol << std::endl;
	}
	//this->set_status(tab_func[this->relation](*this->fact1, *this->fact2));
}

std::ostream & operator<<(std::ostream & o, const Fact & fact)
{
	o << "Symbol: " << fact.symbol << std::endl;
	return o;
}