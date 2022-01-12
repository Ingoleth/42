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

		BTNode(const T& _data, BTNode *parent) : data(_data) //Assumes that data is not equal to parent data; Sets the parents data pointer to the instance;
		{

			top = parent;
			left = 0;
			right = 0;
			if (parent) // Might not be Technically needed...
			{
				if (parent->data > data)
					parent->left = this;
				else
					parent->right = this;
			}
		}

		~BTNode()
		{
			if (left)
				delete left;
			if (right)
				delete right;
		}

		void remove(const T& _data, BTNode **root)
		{
			BTNode *aux = removeNode(_data, root);
			
			if (!aux)
				return;
			delete aux;
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
				return (findSmallestNode(currentNode->right));
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
				return (findBiggestNode(currentNode->left));
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
			std::cout << "Parent = " << top << " (" << (this->top ? this->top->data : 0) << ")\n";
			std::cout << "Left = " << left << " (" << (this->left ? this->left->data : 0) << ")\n";
			std::cout << "Right = " << right << " (" << (this->right ? this->right->data : 0) << ")\n";
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
			size_t sangría = Node->depth(Node);
			while (sangría--)
				std::cout << '\t';
			std::cout << Node->data << "\n";
			displayTree(Node->left);
		}

		void balanceTree(BTNode **Node)
		{
			if (!*Node)
				return;

			int imbalance = heigth((*Node)->left) - heigth((*Node)->right);
			BTNode *aux = NULL;

			while (imbalance <= -2)
			{
				aux = *Node;
				*Node = (*Node)->right;
				(*Node)->top = aux->top;
				aux->right = NULL;
				insert_node(aux, *Node);
				imbalance += 2;
			}
			while (imbalance >= 2)
			{
				aux = *Node;
				*Node = (*Node)->left;
				(*Node)->top = aux->top;
				aux->left = NULL;
				insert_node(aux, *Node);
				imbalance -= 2;
			}
			balanceTree(&(*Node)->left);
			balanceTree(&(*Node)->right);
		}

	private:
		
		void insert_node(BTNode *node, BTNode *parent)
		{
			if (!node || !parent)
				return ;
			findInNode(node->data, parent, &parent);
			if (parent->data < node->data)
				parent->right = node;
			else
				parent->left = node;
			node->top = parent;
		}

		BTNode *removeNode(const T& _data, BTNode **root) //Override so it does the search elsewhere?
		{
			BTNode *aux = NULL;

			if (!*root || !(aux = findInNode(_data, *root)))
				return (NULL);
			if (*root == aux)
			{
				*root = (*root)->right;
				(*root)->top = NULL;
				insert_node(aux->left, *root);
			}
			else
			{
				if (aux->top->data < aux->data)
					aux->top->right = NULL;
				else
					aux->top->left = NULL;
				insert_node(aux->left, aux->top);
				insert_node(aux->right, aux->top);
			}
			aux->left = NULL;
			aux->right = NULL;
			aux->top = NULL;
			return (aux);
		}

	};

		template <class T>
		BTNode<T> *findInNode(T to_find, BTNode<T> *node)
		{
			if (!node)
				return (NULL);
			if (to_find == node->data)
				return (node);
			else if (to_find < node->data)
				return (findInNode(to_find, node->left));
			return (findInNode(to_find, node->right));
		}

		template <class T>
		BTNode<T> *findInNode(T to_find, BTNode<T> *node, BTNode<T> **lastNode)
		{
			if (!node)
				return (NULL);
			if (to_find == node->data)
				return (node);
			*lastNode = node;
			if (to_find < node->data)
				return (findInNode(to_find, node->left, lastNode));
			return (findInNode(to_find, node->right, lastNode));
		}

		template <class T>
		BTNode<T> *findSmallestNode(BTNode<T> *node)
		{
			if (node)
			{
				while (node->left)
					node = node->left;
			}
			return node;
		}

		template <class T>
		BTNode<T> *findBiggestNode(BTNode<T> *node)
		{
			if (node)
			{
				while (node->right)
					node = node->right;
			}
			return node;
		}

		template <class T>
		pair<ft::BTNode<T> *, bool>addNode(const T& _data, BTNode<T> **root) //There's much to do here...
		{
			BTNode<T> *aux;

			if (!*root)
			{
				*root = new BTNode<T>(_data);
				return ft::make_pair(*root, true);
			}
			if (findInNode(_data, *root, &aux))
				return ft::make_pair(aux, false);
			return(ft::make_pair(new BTNode<T>(_data, aux), true));
		}
}
#endif