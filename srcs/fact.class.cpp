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

Fact::Fact(int type, const char symbol, int status) : type(type), symbol(symbol), status(status)
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

int	Fact::get_status(int testing)
{
	if (this->type == FORMULA)
	{
		Formula *formula = static_cast<Formula *>(this);
		return formula->get_status(testing);
	}
	return this->status;
}

int	Fact::set_status(int status, int testing)
{
	if (this->type == FORMULA)
	{
		Formula *formula = static_cast<Formula *>(this);
		return formula->set_status(status, testing);
	}
	if (((this->status == F_TRUE || this->status == F_TRUE + testing) && status <= T2_FALSE)
			|| ((this->status == F_FALSE || this->status == F_FALSE + testing) && status >= F_TRUE))
	{
		if (!testing)
			error_n_exit("Contradiction in the facts...\n");
		else
			return ERROR;
	}
	if (this->status == status || this->status == F_TRUE || this->status == F_FALSE)
		return NON_ACTUALISED;
	if (testing == 2 && this->status + 1 == status)
		status -= 2;
	this->status = status;
	return ACTUALISED;
}

int	Fact::compute_status(int testing)
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

void	Fact::clean(void)
{
	if (this->type == FORMULA)
	{
		Formula *formula = static_cast<Formula *>(this);
		formula->clean();
	}
	else
	{
		if (this->status != F_TRUE && this->status != F_FALSE)
			this->status = PENDING;
	}
}

int	Fact::propagate_status(int testing)
{
	if (this->type == FORMULA)
	{
		Formula *formula = static_cast<Formula *>(this);
		return formula->tab_propagate[formula->relation](*formula, testing);
	}
	return PENDING;
}

std::ostream & operator<<(std::ostream & o, const Fact & fact)
{
	o << "Symbol: " << fact.symbol << std::endl;
	return o;
}