/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:03:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/28 16:57:25 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_system.hpp"

Formula::Formula(int type, Fact *fact1, Fact *fact2, int relation)
{
	this->type = type;
	this->fact1 = fact1;
	this->fact2 = fact2;
	this->relation = relation;
}

Formula::~Formula(void)
{
	return ;
}

int	Formula::not_operator(int status1, int status2, int testing)
{
	(void)status2;

	if (status1 == F_FALSE || status1 == F_FALSE + testing)
		return (F_TRUE + testing);
	else if (status1 == F_TRUE || status1 == F_TRUE + testing)
		return (F_FALSE + testing);
	return PENDING;
}

int	Formula::and_operator(int status1, int status2, int testing)
{	
	if (status1 == F_FALSE || status1 == F_FALSE + testing || status2 == F_FALSE || status2 == F_FALSE + testing)
		return (F_FALSE + testing);
	else if ((status1 == F_TRUE || status1 == F_TRUE + testing) && (status2 == F_TRUE || status2 == F_TRUE + testing))
		return (F_TRUE + testing);
	return PENDING;
}

int	Formula::or_operator(int status1, int status2, int testing)
{
	if (status1 == F_TRUE || status1 == F_TRUE + testing || status2 == F_TRUE || status2 == F_TRUE + testing)
		return (F_TRUE + testing);
	else if ((status1 == F_FALSE || status1 == F_FALSE + testing) && (status2 == F_FALSE || status2 == F_FALSE + testing))
		return (F_FALSE + testing);
	return PENDING;
}

int	Formula::xor_operator(int status1, int status2, int testing)
{
	if (((status1 == F_TRUE || status1 == F_TRUE + testing)
			&& (status2 == F_FALSE || status2 == F_FALSE + testing))
			|| ((status1 == F_FALSE || status1 == F_FALSE + testing)
			&& (status2 == F_TRUE || status2 == F_TRUE + testing)))
		return (F_TRUE + testing);
	else if (((status1 == F_FALSE || status1 == F_FALSE + testing)
			&& (status2 == F_FALSE || status2 == F_FALSE + testing))
			|| ((status1 == F_TRUE || status1 == F_TRUE + testing)
			&& (status2 == F_TRUE || status2 == F_TRUE + testing)))
		return (F_FALSE + testing);
	return PENDING;
}

int (*Formula::tab_operators[NB_OPERATOR])(int, int, int) =
{
	Formula::not_operator,
	Formula::xor_operator,
	Formula::or_operator,
	Formula::and_operator
};

int	Formula::not_propagate(Formula &formula, int testing)
{
	int ret = NON_ACTUALISED;

	if (formula.status == F_TRUE || formula.status == F_TRUE + testing)
		ret = formula.fact1->set_status((F_FALSE + testing), testing);
	else if (formula.status == F_FALSE || formula.status == F_FALSE + testing)
		ret = formula.fact1->set_status((F_TRUE + testing), testing);
	return ret;
}

int	Formula::and_propagate(Formula &formula, int testing)
{
	int ret = NON_ACTUALISED;
	int	status1 = formula.fact1->get_status(testing);
	int status2 = formula.fact2->get_status(testing);

	if (formula.status == F_TRUE || formula.status == F_TRUE + testing)
	{
		ret = formula.fact1->set_status((F_TRUE + testing), testing);
		ret |= formula.fact2->set_status((F_TRUE + testing), testing);
	}
	else if (formula.status == F_FALSE && !testing)
	{
		if (status1 == F_TRUE && status2 == F_TRUE)
			error_n_exit("Contradiction in the facts...\n");
	}
	else
	{
		if ((status1 == F_TRUE || status1 == F_TRUE + testing)
				&& (status2 == F_TRUE || status2 == F_TRUE + testing))
			return ERROR;
	}
	return ret;
}

int	Formula::or_propagate(Formula &formula, int testing)
{
	int ret;
	int status1 = formula.fact1->get_status(testing);
	int status2 = formula.fact2->get_status(testing);

	if (formula.status == F_TRUE || formula.status == F_TRUE + testing)
	{
		if ((status1 == F_FALSE ||status1 == F_FALSE + testing)
				&& (status2 == F_FALSE || status2 == F_FALSE + testing))
		{
			if (testing)
				return ERROR;
			error_n_exit("Contradiction in the facts...\n");
		}
		else if (status1 == F_FALSE || status1 == F_FALSE + testing)
			return formula.fact2->set_status((F_TRUE + testing), testing);
		else if (status2 == F_FALSE || status2 == F_FALSE + testing)
			return formula.fact1->set_status((F_TRUE + testing), testing);
	}
	else if (formula.status == F_FALSE || formula.status == F_FALSE + testing)
	{
		if (status1 == F_TRUE || status1 == F_TRUE + testing
				|| status2 == F_TRUE || status2 == F_TRUE + testing)
		{
			if (testing)
				return ERROR;
			error_n_exit("Contradiction in the facts...\n");
		}
		else
		{
			ret = formula.fact1->set_status((F_FALSE + testing), testing);
			return (ret | formula.fact2->set_status((F_FALSE + testing), testing));
		}
	}
	return NON_ACTUALISED;
}

int	Formula::xor_propagate(Formula &formula, int testing)
{
	int status1 = formula.fact1->get_status(testing);
	int status2 = formula.fact2->get_status(testing);

	if (formula.status == F_TRUE || formula.status == F_TRUE + testing)
	{
		if (((status1 == F_TRUE || status1 == F_TRUE + testing)
				&& (status2 == F_TRUE || status2 == F_TRUE + testing))
				|| ((status1 == F_FALSE || status1 == F_FALSE + testing)
				&& (status2 == F_FALSE || status2 == F_FALSE + testing)))
		{
			if (testing)
				return ERROR;
			error_n_exit("Contradiction in the facts...\n");
		}
		else if (status1 == F_TRUE || status1 == F_TRUE + testing)
			return formula.fact2->set_status((F_FALSE + testing), testing);
		else if (status2 == F_TRUE || status2 == F_TRUE + testing)
			return formula.fact1->set_status((F_FALSE + testing), testing);
		else if (status1 == F_FALSE || status1 == F_FALSE + testing)
			return formula.fact2->set_status((F_TRUE + testing), testing);
		else if (status2 == F_FALSE || status2 == F_FALSE + testing)
			return formula.fact1->set_status((F_TRUE + testing), testing);
	}
	else
	{
		if (((status1 == F_TRUE || status1 == F_TRUE + testing)
				&& (status2 == F_FALSE || status2 == F_FALSE + testing))
				|| ((status1 == F_FALSE || status1 == F_FALSE + testing)
				&& (status2 == F_TRUE || status2 == F_TRUE + testing)))
		{
			if (testing)
				return ERROR;
			error_n_exit("Contradiction in the facts...\n");			
		}
		else if (status1 == F_TRUE || status1 == F_TRUE + testing)
			return formula.fact2->set_status((F_TRUE + testing), testing);
		else if (status2 == F_TRUE || status2 == F_TRUE + testing)
			return formula.fact1->set_status((F_TRUE + testing), testing);
		else if (status1 == F_FALSE || status1 == F_FALSE + testing)
			return formula.fact2->set_status((F_FALSE + testing), testing);
		else if (status2 == F_FALSE || status2 == F_FALSE + testing)
			return formula.fact1->set_status((F_FALSE + testing), testing);
	}
	return NON_ACTUALISED;
}

int (*Formula::tab_propagate[NB_OPERATOR])(Formula&, int) =
{
	Formula::not_propagate,
	Formula::xor_propagate,
	Formula::or_propagate,
	Formula::and_propagate
};

int	Formula::propagate_status(int testing)
{
	return tab_propagate[this->relation](*this, testing);
}

int	Formula::set_status(int status, int testing)
{
	int ret = ACTUALISED;

	if (((this->status == F_TRUE || this->status == F_TRUE + testing) && status == F_FALSE + testing)
			|| ((this->status == F_FALSE || this->status == F_FALSE + testing) && status == F_TRUE + testing))
	{
		if (!testing)
			error_n_exit("Contradiction in the facts...\n");
		else
			return ERROR;
	}
	if (this->status == status || this->status == F_TRUE || this->status == F_FALSE)
	{
		status = this->status;
		ret = NON_ACTUALISED;
	}
	if (testing == 2 && this->status + 1 == status)
	{
		status -= 2;
		is_restart = true;
	}
	this->status = status;
	// ret |= this->propagate_status(testing);
	return ret;
}

int	Formula::get_status(int testing)
{
	if (this->fact2)
		return tab_operators[this->relation](this->fact1->get_status(testing), this->fact2->get_status(testing), testing);
	return this->status;
}

int	Formula::compute_status(int testing)
{
	int	status2 = F_TRUE + testing;
	int	prev_status = this->get_status(testing);
	int	ret = NON_ACTUALISED;

	ret = this->fact1->compute_status(testing);
	if (this->fact2 != nullptr)
	{
		ret |= this->fact2->compute_status(testing);
		if (ret & ERROR)
			return ERROR;
		status2 = this->fact2->get_status(testing);
	}
	if (this->set_status(tab_operators[this->relation](this->fact1->get_status(testing), status2, testing), testing) == ERROR)
		return ERROR;
	if (this->get_status(testing) != prev_status)
		return ACTUALISED;
	return ret;
}

int	Formula::compute_propagate_status(int testing)
{
	int ret;

	ret = this->propagate_status(testing);

	if (ret == ERROR)
		return ret;
	ret |= this->fact1->compute_propagate_status(testing);
	if (ret & ERROR)
		return ret;
	if (this->fact2 != nullptr)
	{
		ret |= this->fact2->compute_propagate_status(testing);
		if (ret & ERROR)
			return ERROR;
	}
	ret |= this->propagate_status(testing);

	return ret;
}

void	Formula::clean()
{
	if (this->status != F_TRUE && this->status != F_FALSE)
		this->status = PENDING;
	this->fact1->clean();
	if (this->fact2)
		this->fact2->clean();
}

std::ostream & operator<<(std::ostream & o, const Formula & formula)
{
	o << "Fact1: " << *(formula.fact1) << std::endl << " Fact2: " << std::endl << *(formula.fact2) << std::endl << "Relation: " << formula.relation << std::endl;
	return o;
}
