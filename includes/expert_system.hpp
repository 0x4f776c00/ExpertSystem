/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_system.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:51:12 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/02 23:52:52 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERT_SYSTEM_HPP
# define EXPERT_SYSTEM_HPP

# include <list>
# include <string>
# include <iostream>
# include <fstream>
# include <vector>

enum e_token_type {INVALID, OPERATOR, FACT, RELATION, SEPARATOR, TRUTH, QUERY};
enum e_relations {NOT, AND, OR, XOR};

# define FORMULA		1
# define NB_OPERATOR	4
# define NB_SNARK		15
# define NON_ACTUALISED	0
# define ACTUALISED		1
# define ERROR			2
# define SET_PENDING	4

# define B_FALSE	-5
# define S_FALSE	-4
# define F_FALSE	-3
# define T1_FALSE	-2
# define T2_FALSE	-1
# define PENDING	0
# define F_TRUE		1
# define T1_TRUE	2
# define T2_TRUE	3
# define S_TRUE		4

constexpr const char *snark_tab[NB_SNARK] =
{
	"Unbelievable. You, [subject name here], must be the pride of [subject hometown here]!",
	"Well done. Here come the test results: \"You are a horrible person.\" That's what it says. We weren't even testing for that.",
	"Please be advised that a noticeable taste of blood is not part of any test protocol.",
	"The Enrichment Center regrets to inform you that this next test is impossible. Make no attempt to solve it.",
	"No further compliance information is required or will be provided, and you are an excellent test subject!",
	"Congratulations! The test is now over.",
	"We are very, very happy for your success.",
	"Where do you think you're going? Because I don't think you're going where you think you're going.",
	"Okay. I am going to kill you now.",
	"I feel sorry for you, really, because you're not even in the right place.",
	"It's funny, actually, when you think about it.",
	"You're not a good person. You know that, right?",
	"This is your fault. It didn't have to be like this.",
	"That crazy thing is not part of any test protocol.",
	"If it makes you feel any better, science has now validated your birth mother's decision to abandon you on a doorstep."
};

extern bool	is_restart;

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
