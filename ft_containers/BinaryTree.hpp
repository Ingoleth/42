#include "Utils.hpp"

namespace ft
{
	template<typename T>
	class BTNode
	{
		public:
			BTNode	*top;
			BTNode	*left;
			BTNode	*right;
			T		data;
		
		BTNode()
		{
			top = 0;
			left = 0;
			right = 0;
		}

		size_t size(BTNode *node)
		{
			if (!node)
				return (true);
			return(1 + size(left) + size(right));
		}

		size_t depth(BTNode *node)
		{
			if (!node)
				return (0);
			return (1 + depth(top));
		}

		size_t heigth(BTNode *node)
		{
			if (node == 0)
				return (-1);
			return(1 + std::max(heigth(left), heigth(right)));
		}

		BTNode *find(T to_find, BTNode *node) //Maybe not make it recurssion based?
		{
			if (!node)
				return (0);
			if (to_find == node->data)
				return (node);
			else if (to_find < node->data)
				return (find(to_find, node->left));
			return (find(to_find, node->right));
		}
	};
}