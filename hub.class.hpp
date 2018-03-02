/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:22:28 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/02 15:12:02 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUB_CLASS_HPP
# define HUB_CLASS_HPP

# include "facts.class.hpp"
# include "expert_system.hpp"

class Facts;
class Axiom;

class Hub
{
	public:

		Hub(void);
		~Hub(void);

		void				add_fact(Facts);
		void				add_axiom(Axiom);

		bool				has_been_actualized(void);
		bool				is_solved(void);
		void				set_actualized_status(bool);
		void				set_solved(void);
		std::list <Facts>	facts;
		std::list <Axiom>	axioms;
		std::string			queries;

	private:

		bool	actualized;
		bool	solved;
};

#endif
