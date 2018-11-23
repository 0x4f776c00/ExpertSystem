/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:42:24 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/23 13:54:01 by bcozic           ###   ########.fr       */
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

		void		xor_propagate(bool);
		void		or_propagate(bool);
		void		and_propagate(bool);
		void		not_propagate(bool);

		e_ret_type	set_status(e_status status, bool testing);
		e_status	get_status(void);
		e_ret_type	compute_status(bool testing);

	private:
		static e_status	(*tab_func[NB_OPERATOR])(e_status, e_status);
};

std::ostream & operator<<(std::ostream & o, const Formula & formula);

#endif
