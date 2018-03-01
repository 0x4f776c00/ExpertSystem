/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:51:12 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/01 15:20:24 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERT_SYSTEM_HPP
# define EXPERT_SYSTEM_HPP

# include <list>
# include <string>
# include <iostream>

# include "axiom.class.hpp"
# include "facts.class.hpp"
# include "formula.class.hpp"
# include "hub.class.hpp"

# define NB_OPERATOR 4

//stat, mmap, getline, strtok

enum e_status {TRUE, FALSE, PENDING, UNKNOW};

#endif
