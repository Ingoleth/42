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

		BTNode(const T& _data) : data(_data)
		{
			top = 0;
			left = 0;
			right = 0;
		}

		~BTNode()
		{
			if (left)
				delete left;
			if (right)
				delete right;
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

		size_t height(BTNode *node)
		{
			if (node == 0)
				return (0);
			return(1 + std::max(height(node->left), height(node->right)));
		}

		BTNode *findSmallestNode(BTNode *node)
		{
			if (node)
			{
				while (node->left)
					node = node->left;
			}
			return node;
		}

		BTNode *findBiggestNode(BTNode *node)
		{
			if (node)
			{
				while (node->right)
					node = node->right;
			}
			return node;
		}

		BTNode *getNext(BTNode *currentNode)
		{
			if (currentNode->right)
				return (findSmallestNode(currentNode->right));
			while (true)
			{
				if (!currentNode)
					break;
				if (currentNode->top->left == currentNode)
					return (currentNode->top);
				currentNode = currentNode->top;
			}
			return (0);
		}

		BTNode *getPrevious(BTNode *currentNode)
		{
			if (currentNode->left)
				return (findBiggestNode(currentNode->left));
			while (true)
			{
				if (!currentNode)
					break;
				if (currentNode->top->right == currentNode)
					return (currentNode->top);
				currentNode = currentNode->top;
			}
			return (0);
		}

		BTNode *copy(BTNode *node)
		{
			if (!node)
				return (0);
			BTNode *aux = new BTNode(node->data);
			aux->left = copy(node->left);
			if (aux->left)
				aux->left->top = aux;
			aux->right = copy(node->right);
			if (aux->right)
				aux->right->top = aux;
			return (aux);
		}

		void displayNodeInfo()
		{
			std::cout << "\n-------------------------------\n";
			std::cout << "Node located at: " << this << std::endl;
			std::cout << "-------------------------------\n";
			std::cout << "Parent = " << top << " (" << (this->top ? this->top->data : T()) << ")\n";
			std::cout << "Left = " << left << " (" << (this->left ? this->left->data : T()) << ")\n";
			std::cout << "Right = " << right << " (" << (this->right ? this->right->data : T()) << ")\n";
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

		void displayTree(BTNode *Node)
		{
			if (!Node)
				return;
			displayTree(Node->right);
			size_t offset = Node->depth(Node);
			while (offset--)
				std::cout << '\t';
			std::cout << Node->data << "\n";
			displayTree(Node->left);
		}
	};

}
#endif