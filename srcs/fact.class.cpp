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

Fact::Fact(int type, const char symbol, int status) : type(type),
		symbol(symbol), status(status)
{
	this->queried = false;
	this->used = false;
	this->set = false;
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
	if (status == PENDING)
		return NON_ACTUALISED;
	if ((this->status == S_TRUE && (status == F_FALSE || status == S_FALSE))
			|| (this->status == S_FALSE && (status == F_TRUE || status == S_TRUE))
			|| ((this->status == F_FALSE || this->status == S_FALSE) && status == S_TRUE)
			|| ((this->status == F_TRUE || this->status == S_TRUE) && status == S_FALSE))
		return SET_PENDING;
	if (((this->status == F_TRUE || this->status == F_TRUE + testing)
			&& status <= T2_FALSE) || ((this->status == F_FALSE
			|| this->status == F_FALSE + testing) && status >= F_TRUE))
	{
		if (testing)
			return ERROR;
		error_n_exit("Contradiction in the facts...\n");
	}
	if (this->status == status || (this->status == F_TRUE
			&& (status == F_TRUE + testing || status == S_TRUE))
			|| (this->status == F_FALSE && (status == F_FALSE + testing
			|| status <= S_FALSE)))
		return NON_ACTUALISED;
	if (testing == 2 && ((this->status == T1_FALSE && status == T2_FALSE)
			|| (this->status == T1_TRUE && status == T2_TRUE)))
	{
		status -= 2;
		is_restart = true;
	}
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

int	Fact::compute_propagate_status(int testing)
{
	if (this->type == FORMULA)
	{
		Formula *formula = static_cast<Formula *>(this);
		return formula->compute_propagate_status(testing);
	}
	else
		return NON_ACTUALISED;
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
		if (this->status != F_TRUE && this->status != F_FALSE
				&& this->status != S_FALSE && this->status != B_FALSE)
			this->status = PENDING;
	}
}

void	Fact::set_s_to_pending(void)
{
	if (this->type == FORMULA)
	{
		Formula *formula = static_cast<Formula *>(this);
		formula->set_s_to_pending();
	}
	else
	{
		if (this->status <= S_FALSE || this->status == S_TRUE)
			this->status = PENDING;
	}
}
