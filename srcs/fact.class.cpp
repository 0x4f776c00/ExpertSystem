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

Fact::Fact(int type, const char symbol, e_status status) : type(type), symbol(symbol), status(status)
{
	this->queried = false;
}

Fact::Fact(void) : symbol('\0')
{
	this->status = PENDING;
}

Fact::~Fact(void)
{
	return ;
}

e_status	Fact::get_status(void)
{
	if (this->type == FORMULA)
	{
		Formula *formula = static_cast<Formula *>(this);
		return formula->get_status();
	}
	return this->status;
}

int	Fact::set_status(e_status status, bool testing)
{
	int ret;
	if (this->type == FORMULA)
	{
		Formula *formula = static_cast<Formula *>(this);
		ret = formula->set_status(status, testing);
		return ret;
	}
		if ((this->status >= F_TRUE && status <= T_FALSE)
				|| (this->status <= T_FALSE && status >= F_TRUE))
		{
			if (!testing)
				error_n_exit("Contradiction in the facts...\n");
			else
				return ERROR;
		}
		if (this->status != PENDING)
			return NON_ACTUALISED;
		this->status = status;
		return ACTUALISED;
}

int	Fact::compute_status(bool testing)
{
	if (this->type == FORMULA)
	{
		Formula *formula = static_cast<Formula *>(this);
		return formula->compute_status(testing);
	}
	else
	{
		return NON_ACTUALISED;
	}
}

std::ostream & operator<<(std::ostream & o, const Fact & fact)
{
	o << "Symbol: " << fact.symbol << std::endl;
	return o;
}