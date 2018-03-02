/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:51:12 by bcozic            #+#    #+#             */
/*   Updated: 2018/03/02 19:10:27 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERT_SYSTEM_HPP
# define EXPERT_SYSTEM_HPP

# include <list>
# include <string>
# include <iostream>
# include <fstream>

enum e_status {F_TRUE, F_FALSE, F_PENDING, F_UNKNOWN};
enum e_token_type {INVALID, OPERATOR, FACT, RELATION, SEPARATOR, TRUTH, QUERY};

# define NB_OPERATOR 4
# define NB_SNARK 3

constexpr const char *snark_tab[NB_SNARK] =
{
	"You are bad, and you should feel bad.",
	"Unbelievable. You, [subject name here], must be the pride of [subject hometown here]!",
	"Well done. Here come the test results: \"You are a horrible person.\" That's what it says. We weren't even testing for that."
};

# include "facts.class.hpp"
# include "hub.class.hpp"
# include "formula.class.hpp"
# include "axiom.class.hpp"
# include "token.struct.hpp"

void	get_system(Hub *hub, char *file_name);
int		error_n_exit(std::string str);

//stat, mmap, getline, strtok

#endif
