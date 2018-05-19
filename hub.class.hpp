/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:22:28 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/19 10:55:38 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUB_CLASS_HPP
# define HUB_CLASS_HPP

# include "fact.class.hpp"
# include "expert_system.hpp"

class Fact;
class Axiom;

class Hub
{
	public:

		Hub(void);
		~Hub(void);

		void				add_axiom(Axiom);

		bool				has_been_actualized(void);
		bool				is_solved(void);
		void				set_actualized_status(bool);
		void				set_solved(void);
		std::vector	<Fact>	facts;
		std::list	<Axiom>	axioms;
		std::string			queries;

	private:

		bool	actualized;
		bool	solved;
};

#endif
