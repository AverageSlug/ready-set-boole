#ifndef NEGATION_NORMAL_FORM_HPP
# define NEGATION_NORMAL_FORM_HPP

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

std::string		negation_normal_form(std::string &formula);

#endif
