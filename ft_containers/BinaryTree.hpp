#include "utils.hpp"
# ifndef BINARY_TREE
# define BINARY_TREE

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
			*lastNode = node;
			if (to_find == node->data)
				return (node);
			if (to_find < node->data)
				return (find(to_find, node->left, lastNode));
			return (find(to_find, node->right, lastNode));
		}

		BTNode *findSmallest(BTNode *node)
		{
			if (node)
			{
				while (node->left)
					node = node->left;
			}
			return node;
		}

		BTNode *findBiggest(BTNode *node)
		{
			if (node)
			{
				while (node->right)
					node = node->right;
			}
			return node;
		}

		pair<ft::BTNode<T> *, bool>add(const T& _data, BTNode *root) //There's much to do here...
		{
			BTNode *aux;

			if (find(_data, root, &aux))
				return make_pair(aux, false);
			return(make_pair(new BTNode(_data, aux), true));
		}

		void remove(const T& _data, BTNode *root)
		{
			BTNode *aux;

			if (!root || !find(_data, root, &aux))
				return ;
			//Handle if root?
			if (aux->top->data < aux->data)
				aux->top->right = NULL;
			else
				aux->top->left = NULL;
			aux->top = NULL;
			aux = aux->findSmallest(aux);
			std::cout << aux->data << std::cout;
			return ;
			for (; aux; aux = aux->getNext(aux)) //REDO LOGIC so it reuses the nodes...
				root->add(aux->data, root);
		}

		size_t size(BTNode *node)
		{
			if (!node)
				return (0);
			return(1 + size(node->left) + size(node->right));
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

		BTNode *getNext(BTNode *currentNode) // Check return value when biggest num?
		{
			if (currentNode->right)
				return (currentNode->right);
			T &auxdata = currentNode->data;
			while (true)
			{
				currentNode = currentNode->top;
				if (!currentNode)
					break;
				if (currentNode->data > auxdata)
					return (currentNode);
			}
			return (0);
		}

		BTNode *getPrevious(BTNode *currentNode) // Check return value when biggest num?
		{
			if (currentNode->left)
				return (currentNode->left);
			T &auxdata = currentNode->data;
			while (true)
			{
				currentNode = currentNode->top;
				if (!currentNode)
					break;
				if (currentNode->data < auxdata)
					return (currentNode);
			}
			return (0);
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

		void displayInOrder(BTNode *root)
		{
			if (root)
			{
				displayInOrder(root->left);
				std::cout << root->data << "\n";
				displayInOrder(root->right);
			}
	}
	};
#endif
}