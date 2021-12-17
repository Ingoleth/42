#include "utils.hpp"

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

		BTNode(const T& _data)
		{
			top = 0;
			left = 0;
			right = 0;
			data = _data;
		}

		BTNode(const T& _data, BTNode *parent) //Assumes that data is not equal to parent data; Sets the parents data pointer to the instance;
		{
			top = parent;
			left = 0;
			right = 0;
			data = _data;
			if (parent) //Technically needed...
			{
				if (parent->data > data)
					parent->left = this;
				else
					parent->right = this;
			}
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

		BTNode *find(T to_find, BTNode *node, BTNode **lastNode)
		{
			if (!node)
				return (0);
			if (to_find == node->data)
				return (node);
			else if (to_find < node->data)
			{
				*lastNode = node;
				return (find(to_find, node->left, lastNode));
			}
			*lastNode = node;
			return (find(to_find, node->right, lastNode));
		}

		void add(const T& _data, BTNode *root)
		{
			BTNode *aux;
			if (find(_data, root, &aux))
				return ;
			aux->displayNodeInfo();
			new BTNode(_data, aux);
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
			return (1 + depth(node->top));
		}

		size_t heigth(BTNode *node)
		{
			if (node == 0)
				return (0);
			return(1 + std::max(heigth(node->left), heigth(node->right)));
		}

		void displayNodeInfo()
		{
			std::cout << "\n-------------------------------\n";
			std::cout << "Node located at: " << this << std::endl;
			std::cout << "-------------------------------\n";
			std::cout << "Parent = " << top << std::endl;
			std::cout << "Left = " << left << std::endl;
			std::cout << "Right = " << right << std::endl;
			std::cout << "Content = " << data << std::endl;
			std::cout << "-------------------------------\n";
		}
	};
}