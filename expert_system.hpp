/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justasze <justasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:51:12 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/10 15:16:19 by justasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERT_SYSTEM_HPP
# define EXPERT_SYSTEM_HPP

# include <list>
# include <string>
# include <iostream>
# include <fstream>
# include <vector>

enum e_status {F_FALSE = -2, T_FALSE = -1, PENDING = 0, UNKNOWN = 1, F_TRUE = 2, T_TRUE = 3};
enum e_token_type {INVALID, OPERATOR, FACT, RELATION, SEPARATOR, TRUTH, QUERY};
enum e_relations {NOT, XOR, OR, AND};
enum e_ret_type {NON_ACTUALISED, ACTUALISED, ERROR};

# define FORMULA 1
# define NB_OPERATOR 4
# define NB_SNARK 3

constexpr const char *snark_tab[NB_SNARK] =
{
	"You are bad, and you should feel bad.",
	"Unbelievable. You, [subject name here], must be the pride of [subject hometown here]!",
	"Well done. Here come the test results: \"You are a horrible person.\" That's what it says. We weren't even testing for that."
};

# include "fact.class.hpp"
# include "hub.class.hpp"
# include "formula.class.hpp"
# include "axiom.class.hpp"
# include "token.struct.hpp"

void	get_system(Hub *hub, char *file_name);
void	parse_system(std::vector <std::vector <Token>> tokens, Hub *hub);
int		error_n_exit(std::string str);
void	solve_system(Hub *hub);

#endif
