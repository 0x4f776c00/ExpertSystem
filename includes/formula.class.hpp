/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:42:24 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/01 00:28:06 by bcozic           ###   ########.fr       */
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

		static int	xor_operator(int, int, int);
		static int	or_operator(int, int, int);
		static int	and_operator(int, int, int);
		static int	not_operator(int, int, int);

		static int	xor_propagate(Formula&, int);
		static int	or_propagate(Formula&, int);
		static int	and_propagate(Formula&, int);
		static int	not_propagate(Formula&, int);

		int	set_status(int status, int testing);
		int	get_status(int testing);
		int	get_state(void);
		int	compute_status(int testing);
		int	propagate_status(int testing);
		int	compute_propagate_status(int testing);

		void	clean(void);
		void	set_s_to_pending(void);
		static int	(*tab_propagate[NB_OPERATOR])(Formula&, int);


	private:
		static int		(*tab_operators[NB_OPERATOR])(int, int, int);
};

std::ostream & operator<<(std::ostream & o, const Formula & formula);

#endif
