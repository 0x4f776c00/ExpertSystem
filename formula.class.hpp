/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:42:24 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/19 10:55:38 by justasze         ###   ########.fr       */
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

		static e_status	xor_operator(Fact, Fact);
		static e_status	or_operator(Fact, Fact);
		static e_status	and_operator(Fact, Fact);
		static e_status	not_operator(Fact, Fact);


		void	compute_status(void);

	private:
		static e_status	(*tab_func[NB_OPERATOR])(Fact, Fact);

		//operator overload
};

std::ostream & operator<<(std::ostream & o, const Formula & formula);

#endif
