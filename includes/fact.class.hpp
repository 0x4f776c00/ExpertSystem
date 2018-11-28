/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fact.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:36:02 by bcozic            #+#    #+#             */
/*   Updated: 2018/05/10 14:21:59 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTS_CLASS_HPP
# define FACTS_CLASS_HPP

#include "expert_system.hpp"
#include "hub.class.hpp"

class Fact : public Hub
{
	public:

		int			type;
		const char	symbol;
		bool		queried;
		bool		used;
		bool		set;
		int			status;

		int	get_status(int testing);
		int	set_status(int status, int testing);

		Fact(int type, const char symbol, int status);
		Fact(void);
		~Fact(void);

		int		compute_status(int testing);
		void	clean(void);
		int		propagate_status(int testing);
};

std::ostream & operator<<(std::ostream & o, const Fact & fact);

#endif
