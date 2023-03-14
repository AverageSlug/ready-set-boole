#ifndef CONJUNCTIVE_NORMAL_FORM_HPP
# define CONJUNCTIVE_NORMAL_FORM_HPP

# include <iostream>
# include <string>

typedef struct		s_bst
{
	char			value;
	bool			negation;
	struct s_bst	*parent;
	struct s_bst	*left;
	struct s_bst	*right;
}					t_bst;

std::string		conjunctive_normal_form(std::string &formula);

#endif
