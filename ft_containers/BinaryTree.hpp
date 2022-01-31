#include "utils.hpp"
# ifndef BINARY_TREE
# define BINARY_TREE

namespace ft
{
	template <class T>
	struct Node
	{
		T data; // holds the key
		Node<T> *parent; // pointer to the parent
		Node<T> *left; // pointer to left child
		Node<T> *right; // pointer to right child
		bool color; // 1 -> Red, 0 -> Black

		Node() : data(), parent(), left(), right(), color(){}
		Node(T _data, bool _color) : data(_data), parent(), left(), right(), color(_color){}

		Node<T> *minimum(Node<T> *node) const
		{
			if (node)
			{
				while (node->left != NULL && node->left->left != NULL)
					node = node->left;
			}
			return node;
		}

		// find the node with the maximum key
		Node<T> *maximum(Node<T> *node) const
		{
			if (node)
			{
				while (node->right != NULL && node->right->right != NULL)
					node = node->right;
			}
			return node;
		}

		Node<T> *getNext(Node<T> *currentNode) const
		{
			if (currentNode->right && currentNode->right->right != NULL)
				return (minimum(currentNode->right));
			Node<T> * aux = currentNode->right;
			while (true)
			{
				if (!currentNode->parent)
					break;
				if (currentNode->parent->left == currentNode)
					return (currentNode->parent);
				currentNode = currentNode->parent;
			}
			return (aux);
		}

		Node<T> *getPrevious(Node<T> *currentNode) const
		{
			if (currentNode->left && currentNode->left->left != NULL)
				return (maximum(currentNode->left));
			Node<T> * aux = currentNode->right;
			while (true)
			{
				if (!currentNode->parent)
					break;
				if (currentNode->parent->right == currentNode)
					return (currentNode->parent);
				currentNode = currentNode->parent;
			}
			return (aux);
		}
	};

	// class RBTree implements the operations in Red Black Tree
	template <class _Key, class _Tp, class _Compare = std::less<_Key>, class _Alloc = std::allocator<ft::pair<const _Key, _Tp> > >
	class RBTree
	{

	private:
		typedef ft::pair<const _Key, _Tp> element;
		typedef Node< element > nodeType;
		typedef nodeType *NodePtr;
		
		NodePtr root;
		NodePtr TNULL;
		_Compare _compare;
		typename _Alloc::template rebind<nodeType>::other	_allocator;

		// initializes the nodes with appropiate values
		// all the pointers are set to point to null
		void initializeNULLNode(NodePtr node, NodePtr parent)
		{
			node->data = 0;
			node->parent = parent;
			node->left = NULL;
			node->right = NULL;
			node->color = 0;
		}

		void preOrderHelper(NodePtr node)
		{
			if (node != TNULL)
			{
				std::cout << node->data << " ";
				preOrderHelper(node->left);
				preOrderHelper(node->right);
			} 
		}

		void inOrderHelper(NodePtr node)
		{
			if (node != TNULL)
			{
				inOrderHelper(node->left);
				std::cout << node->data << " ";
				inOrderHelper(node->right);
			} 
		}

		void postOrderHelper(NodePtr node)
		{
			if (node != TNULL)
			{
				postOrderHelper(node->left);
				postOrderHelper(node->right);
				std::cout << node->data << " ";
			} 
		}

		NodePtr searchTreeHelper(NodePtr node, _Key key) const
		{
			if (node == TNULL)
				return NULL;
			else if (key == node->data.first)
				return node;
			else
			{
				if (_compare(key, node->data.first))
					return searchTreeHelper(node->left, key);
				return searchTreeHelper(node->right, key);
			}
		}

		// fix the rb tree modified by the delete operation
		void fixDelete(NodePtr x)
		{
			NodePtr s;
			while (x != root && x->color == 0)
			{
				if (x == x->parent->left)
				{
					s = x->parent->right;
					if (s->color == 1)
					{
						// case 3.1
						s->color = 0;
						x->parent->color = 1;
						leftRotate(x->parent);
						s = x->parent->right;
					}

					if (s->left->color == 0 && s->right->color == 0)
					{
						// case 3.2
						s->color = 1;
						x = x->parent;
					}
					else
					{
						if (s->right->color == 0) {
							// case 3.3
							s->left->color = 0;
							s->color = 1;
							rightRotate(s);
							s = x->parent->right;
						} 

						// case 3.4
						s->color = x->parent->color;
						x->parent->color = 0;
						s->right->color = 0;
						leftRotate(x->parent);
						x = root;
					}
				}
				else
				{
					s = x->parent->left;
					if (s->color == 1)
					{
						// case 3.1
						s->color = 0;
						x->parent->color = 1;
						rightRotate(x->parent);
						s = x->parent->left;
					}

					if (s->right->color == 0 && s->right->color == 0)
					{
						// case 3.2
						s->color = 1;
						x = x->parent;
					}
					else
					{
						if (s->left->color == 0) {
							// case 3.3
							s->right->color = 0;
							s->color = 1;
							leftRotate(s);
							s = x->parent->left;
						} 

						// case 3.4
						s->color = x->parent->color;
						x->parent->color = 0;
						s->left->color = 0;
						rightRotate(x->parent);
						x = root;
					}
				} 
			}
			x->color = 0;
		}

		void rbTransplant(NodePtr u, NodePtr v)
		{
			if (u->parent == NULL)
				root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}
		
		// fix the red-black tree
		void fixInsert(NodePtr k){
			NodePtr u;
			while (k->parent->color == 1)
			{
				if (k->parent == k->parent->parent->right)
				{
					u = k->parent->parent->left; // uncle
					if (u->color == 1) {
						// case 3.1
						u->color = 0;
						k->parent->color = 0;
						k->parent->parent->color = 1;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->left)
						{
							// case 3.2.2
							k = k->parent;
							rightRotate(k);
						}
						// case 3.2.1
						k->parent->color = 0;
						k->parent->parent->color = 1;
						leftRotate(k->parent->parent);
					}
				}
				else
				{
					u = k->parent->parent->right; // uncle

					if (u->color == 1)
					{
						// mirror case 3.1
						u->color = 0;
						k->parent->color = 0;
						k->parent->parent->color = 1;
						k = k->parent->parent;	
					} else
					{
						if (k == k->parent->right)
						{
							// mirror case 3.2.2
							k = k->parent;
							leftRotate(k);
						}
						// mirror case 3.2.1
						k->parent->color = 0;
						k->parent->parent->color = 1;
						rightRotate(k->parent->parent);
					}
				}
				if (k == root)
				{
					break;
				}
			}
			root->color = 0;
		}

		size_t sizeHelper(NodePtr node) const
		{
			if (node == TNULL)
				return 0;
			int i = 1 + sizeHelper(node->left) + sizeHelper(node->right);
			return (i);
		}

		void printHelper(NodePtr root, std::string indent, bool last)
		{
			// print the tree structure on the screen
			if (root != TNULL)
			{
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "     ";
				}
				else
				{
					std::cout << "L----";
					indent += "|    ";
				}
					
				std::string sColor = root->color?"RED":"BLACK";
				std::cout << root->data << "(" << sColor <<")" << std::endl;
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
			}
			// std::cout <<root->left->data <<std::endl;
		}

		void deletetree(NodePtr node)
		{
			if (node->left != TNULL)
				deletetree(node->left);
			if (node->right != TNULL)
				deletetree(node->right);
			_allocator.destroy(node);
			_allocator.deallocate(node, 1);
		}

	public:
		typedef ft::Node<ft::pair<int, int> > *element_ptr;

		RBTree(const _Compare& comp = _Compare(),
			const _Alloc& alloc = _Alloc()) : _compare(comp), _allocator(alloc)
		{
			TNULL = _allocator.allocate(1);
			_allocator.construct(TNULL, nodeType());
			root = TNULL;
		}

		RBTree(const RBTree &src) : _compare(src._compare), _allocator(src._allocator)
		{
			TNULL = _allocator.allocate(1);
			_allocator.construct(TNULL, nodeType());
			root = copy(src.getRoot(), src.getTNull(), TNULL);
		}

		~RBTree()
		{
			if (root != TNULL)
				deletetree(root);
			_allocator.destroy(TNULL);
			_allocator.deallocate(TNULL, 1);
		}

		RBTree &operator=(RBTree const &src)
		{
			if (this->root != TNULL)
				deletetree(root);
			root = copy(src.getRoot(), src.getTNull(), TNULL);
			return (*this);
		}

		// Pre-Order traversal
		// Node->Left Subtree->Right Subtree
		void preorder() {
			preOrderHelper(this->root);
		}

		// In-Order traversal
		// Left Subtree -> Node -> Right Subtree
		void inorder() {
			inOrderHelper(this->root);
		}

		// Post-Order traversal
		// Left Subtree -> Right Subtree -> Node
		void postorder() {
			postOrderHelper(this->root);
		}

		// search the tree for the key k
		// and return the corresponding node
		NodePtr searchTree(_Key key) const
		{
			return searchTreeHelper(this->root, key);
		}

		// find the node with the minimum key
		NodePtr minimum(NodePtr node) const
		{
			if (node != TNULL)
			{
				while (node->left != TNULL)
				{
					node = node->left;
				}
			}
			return node;
		}

		// find the node with the maximum key
		NodePtr maximum(NodePtr node) const
		{
			if (node != TNULL)
			{
				while (node->right != TNULL)
				{
					node = node->right;
				}
			}
			return node;
		}

		// find the successor of a given node
		NodePtr successor(NodePtr x) {
			// if the right subtree is not null,
			// the successor is the leftmost node in the
			// right subtree
			if (x->right != TNULL) {
				return minimum(x->right);
			}

			// else it is the lowest ancestor of x whose
			// left child is also an ancestor of x.
			NodePtr y = x->parent;
			while (y != TNULL && x == y->right) {
				x = y;
				y = y->parent;
			}
			return y;
		}

		// find the predecessor of a given node
		NodePtr predecessor(NodePtr x) {
			// if the left subtree is not null,
			// the predecessor is the rightmost node in the 
			// left subtree
			if (x->left != TNULL) {
				return maximum(x->left);
			}

			NodePtr y = x->parent;
			while (y != TNULL && x == y->left) {
				x = y;
				y = y->parent;
			}

			return y;
		}

		// rotate left at node x
		void leftRotate(NodePtr x) {
			NodePtr y = x->right;
			x->right = y->left;
			if (y->left != TNULL) {
				y->left->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL) {
				this->root = y;
			} else if (x == x->parent->left) {
				x->parent->left = y;
			} else {
				x->parent->right = y;
			}
			y->left = x;
			x->parent = y;
		}

		// rotate right at node x
		void rightRotate(NodePtr x) {
			NodePtr y = x->left;
			x->left = y->right;
			if (y->right != TNULL) {
				y->right->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == NULL) {
				this->root = y;
			} else if (x == x->parent->right) {
				x->parent->right = y;
			} else {
				x->parent->left = y;
			}
			y->right = x;
			x->parent = y;
		}

		// insert the key to the tree in its appropriate position
		// and fix the tree
		ft::pair<NodePtr, bool>
		insert(element data)
		{
			NodePtr node;
			// Ordinary Binary Search Insertion
			if (root != TNULL && (node = searchTree(data.first)))
				return ft::make_pair(node, false);

			node = _allocator.allocate(1);
			_allocator.construct(node, nodeType(data, 1)); // new node must be red
			node->left = TNULL;
			node->right = TNULL;

			NodePtr y = NULL;
			NodePtr x = this->root;

			while (x != TNULL)
			{
				y = x;
				if (_compare(node->data.first, x->data.first))
					x = x->left;
				else
					x = x->right;
			}
			// y is parent of x
			node->parent = y;
			if (y == NULL)
				root = node;
			else if (_compare(node->data.first, y->data.first))
				y->left = node;
			else
				y->right = node;
			// if new node is a root node, simply return
			if (node->parent == NULL)
			{
				node->color = 0;
				TNULL->parent = maximum(root);
				return ft::make_pair(node, true);
			}
			// if the grandparent is null, simply return
			if (node->parent->parent == NULL)
			{
				TNULL->parent = maximum(root);
				return ft::make_pair(node, true);
			}

			// Fix the tree
			fixInsert(node);
			TNULL->parent = maximum(root);
			return ft::make_pair(node, true);
		}

		NodePtr getRoot() const
		{
			return this->root;
		}

		NodePtr getTNull() const {
			return this->TNULL;
		}

		_Compare getCompare() const
		{
			return this->_compare;
		}

		// delete the node from the tree
		bool deleteNode(_Key key)
		{
			NodePtr z;
			NodePtr x, y;
			
			if (!(z = searchTree(key)))
				return (false);
			y = z;
			int y_original_color = y->color;
			if (z->left == TNULL)
			{
				x = z->right;
				rbTransplant(z, z->right);
			}
			else if (z->right == TNULL)
			{
				x = z->left;
				rbTransplant(z, z->left);
			}
			else
			{
				y = minimum(z->right);
				y_original_color = y->color;
				x = y->right;
				if (y->parent == z) {
					x->parent = y;
				} else {
					rbTransplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}

				rbTransplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			_allocator.destroy(z);
			_allocator.deallocate(z, 1);
			if (y_original_color == 0)
				fixDelete(x);
			TNULL->parent = maximum(root);
			return (true);
		}

		NodePtr getNext(NodePtr currentNode) const
		{
			if (currentNode->right != TNULL)
				return (minimum(currentNode->right));
			while (true)
			{
				if (!currentNode->parent)
					break;
				if (currentNode->parent->left == currentNode)
					return (currentNode->parent);
				currentNode = currentNode->parent;
			}
			return (TNULL);
		}
		
		NodePtr getPrevious(NodePtr currentNode) const
		{
			if (currentNode->left != TNULL)
				return (maximum(currentNode->left));
			while (true)
			{
				if (!currentNode->parent)
					break;
				if (currentNode->parent->right == currentNode)
					return (currentNode->parent);
				currentNode = currentNode->parent;
			}
			return (0);
		}

		NodePtr copy(NodePtr node, NodePtr prevTNull, NodePtr NewTNull)
		{
			NodePtr aux = _allocator.allocate(1);
			_allocator.construct(aux, nodeType(node->data, node->color));
			if (node->left == prevTNull)
				aux->left = NewTNull;
			else
			{
				aux->left = copy(node->left, prevTNull, NewTNull);
				aux->left->parent = aux;
			}
			if (node->right == prevTNull)
				aux->right = NewTNull;
			else
			{
				aux->right = copy(node->right, prevTNull, NewTNull);
				aux->right->parent = aux;
			}
			return (aux);
		}

		bool empty ( void ) const
		{
			if (root == TNULL)
				return true;
			return false;
		}

		size_t size( void ) const
		{
			return sizeHelper(this->root);
		}

		void clear( void )
		{
			this->deletetree(root);
			root = TNULL;
		}

		// print the tree structure on the screen
		void prettyPrint() {
			if (root) {
				printHelper(this->root, "", true);
			}
		}

	};

}

#endif