#include <string>
#include <iostream>

typedef struct		s_bst
{
	char			value;
	bool			negation;
	struct s_bst	*parent;
	struct s_bst	*left;
	struct s_bst	*right;
}					t_bst;

std::string		negation_normal_form(std::string &formula)
{
	t_bst			*tree = NULL;
	t_bst			*tmp = NULL;
	std::string		return_formula;
	int				side = 0, n = 0;

	for (int i = 0; formula[i]; i++)
		if (formula[i] == '!')
			n++;
	if (!((formula.size() - n) % 2) || (formula.size() > 1 && formula[formula.size() - 1] >= 'A' && formula[formula.size() - 1] <= 'Z'))
	{
		std::cout << "Invalid formula" << std::endl;
		return ("");
	}
	for (int i = formula.size() - 1; i >= 0; i--)
	{
		tree = new t_bst;
		tree->parent = tmp;
		if (tmp)
		{
			if (side)
				tmp->left = tree;
			else
				tmp->right = tree;
		}
		tree->left = NULL;
		tree->right = NULL;
		tree->negation = false;
		while (formula[i] == '!')
		{
			tree->negation = !tree->negation;
			i--;
		}
		tree->value = formula[i];
		if (!i)
			break ;
		else if (formula[i] == '&' || formula[i] == '|' || formula[i] == '>' || formula[i] == '=' || formula[i] == '^')
			if (!tree->right)
			{
				tmp = tree;
				tree = tree->right;
				side = 0;
			}
			else if (!tree->left)
			{
				tmp = tree;
				tree = tree->left;
				side = 1;
			}
			else
			{
				std::cout << "Invalid formula" << std::endl;
				return ("");
			}
		else if (formula[i] >= 'A' && formula[i] <= 'Z')
		{
			while (tree->parent && tree->parent->left)
				tree = tree->parent;
			if (tree->parent->left)
			{
				std::cout << "Invalid formula" << std::endl;
				return ("");
			}
			tmp = tree->parent;
			tree = tree->parent->left;
			side = 1;
		}
		else
		{
			std::cout << "Invalid formula" << std::endl;
			return ("");
		}
	}
	while (tree->parent)
		tree = tree->parent;
	while (42)
	{
		if (tree->negation && (tree->value == '&' || tree->value == '|'))
		{
			tree->value = 162 - tree->value;
			tree->negation = false;
			tree->left->negation = !tree->left->negation;
			tree->right->negation = !tree->right->negation;
		}
		else if (tree->value == '>')
		{
			if (tree->negation)
			{
				tree->value = '&';
				tree->right->negation = !tree->right->negation;
				tree->negation = false;
			}
			else
			{
				tree->value = '|';
				tree->left->negation = !tree->left->negation;
			}
		}
		else if (tree->value == '=' || tree->value == '^')
		{
			t_bst	*node = new t_bst;
			node->negation = tree->negation;
			if (tree->value == '^')
				node->negation = !node->negation;
			node->value = '|';
			tree->value = '&';
			tree->negation = false;
			node->parent = tree->parent;
			if (tree->parent)
			{
				if (tree == tree->parent->left)
					tree->parent->left = node;
				else
					tree->parent->right = node;
			}
			t_bst	*copy = new t_bst;
			copy->parent = node;
			copy->left = NULL;
			copy->right = NULL;
			copy->value = '&';
			copy->negation = false;
			while (69)
			{
				if (tree->left)
				{
					tree = tree->left;
					tmp = copy;
					copy = copy->left;
					side = 1;
				}
				else if (tree->right)
				{
					std::cout << "Invalid formula" << std::endl;
					return ("");
				}
				else if (tree->parent)
				{
					if (tree->parent && tree == tree->parent->right && tree->parent != node->parent)
					{
						while (tree->parent && tree == tree->parent->right && tree->parent != node->parent)
						{
							tree = tree->parent;
							copy = copy->parent;
						}
						if (tree->parent == node->parent)
							break ;
					}
					tree = tree->parent->right;
					tmp = copy->parent;
					copy = copy->parent->right;
					side = 0;
				}
				else
				{
					std::cout << "Invalid formula" << std::endl;
					return ("");
				}
				copy = new t_bst;
				copy->parent = tmp;
				if (side)
					tmp->left = copy;
				else
					tmp->right = copy;
				copy->left = NULL;
				copy->right = NULL;
				copy->value = tree->value;
				if (copy->parent && node == copy->parent->parent)
					copy->negation = !tree->negation;
				else
					copy->negation = tree->negation;
			}
			tree->parent = node;
			node->left = tree;
			node->right = copy;
			tree = node;
			continue ;
		}
		if (tree->left)
			tree = tree->left;
		else if (tree->right)
		{
			std::cout << "Invalid formula" << std::endl;
			return ("");
		}
		else if (tree->parent && tree != tree->parent->right)
			tree = tree->parent->right;
		else if (tree->parent && tree == tree->parent->right)
		{
			while (tree->parent && tree == tree->parent->right)
				tree = tree->parent;
			if (tree->parent && tree->parent->right)
				tree = tree->parent->right;
			else
				break ;
		}
		else
			break ;
	}
	while (tree->parent)
		tree = tree->parent;
	while (19)
	{
		if (tree->left)
			tree = tree->left;
		else if (tree->right)
		{
			std::cout << "Invalid formula" << std::endl;
			return ("");
		}
		else if (tree->parent && tree->parent->right)
		{
			return_formula.push_back(tree->value);
			if (tree->negation)
				return_formula.push_back('!');
			if (tree == tree->parent->right)
			{
				while (tree->parent && tree == tree->parent->right)
				{
					tree = tree->parent;
					return_formula.push_back(tree->value);
					if (tree->negation)
							return_formula.push_back('!');
				}
				if (!tree->parent)
					break ;
			}
			tree = tree->parent->right;
		}
		else
		{
			return_formula.push_back(tree->value);
			if (tree->negation)
				return_formula.push_back('!');
			break ;
		}
	}
	return (return_formula);
}
