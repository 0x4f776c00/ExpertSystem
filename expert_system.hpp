/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:51:12 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/02 17:58:44 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERT_SYSTEM_HPP
# define EXPERT_SYSTEM_HPP

# include <list>
# include <string>
# include <iostream>
# include <fstream>

enum e_status {F_TRUE, F_FALSE, F_PENDING, F_UNKNOWN};
enum e_token_type {OPERATOR = 1, FACT, RELATION, SEPARATOR, TRUTH, QUERY};

# define NB_OPERATOR 4

# include "facts.class.hpp"
# include "hub.class.hpp"
# include "formula.class.hpp"
# include "axiom.class.hpp"
# include "token.struct.hpp"

void	get_system(Hub *hub, char *file_name);

//stat, mmap, getline, strtok

#endif
