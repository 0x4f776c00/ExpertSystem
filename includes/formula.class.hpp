/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:42:24 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/23 18:46:45 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMULA_CLASS_HPP
# define FORMULA_CLASS_HPP

#include "expert_system.hpp"

class Formula : public Fact
{
	public:

		Fact	*fact1;
		Fact	*fact2;
		int		relation; //Position in fonction tab

		Formula(int type, Fact *f1, Fact *f2, int relation);
		~Formula(void);

		static e_status	xor_operator(e_status, e_status);
		static e_status	or_operator(e_status, e_status);
		static e_status	and_operator(e_status, e_status);
		static e_status	not_operator(e_status, e_status);

		static int	xor_propagate(Formula&, bool);
		static int	or_propagate(Formula&, bool);
		static int	and_propagate(Formula&, bool);
		static int	not_propagate(Formula&, bool);

		int	set_status(e_status status, bool testing);
		e_status	get_status(void);
		e_status	get_state(void);
		int	compute_status(bool testing);
		int	propagate_status(bool testing);

	private:
		static e_status		(*tab_operators[NB_OPERATOR])(e_status, e_status);
		static int	(*tab_propagate[NB_OPERATOR])(Formula&, bool);
};

std::ostream & operator<<(std::ostream & o, const Formula & formula);

#endif
