#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <math.h>
#include <iostream>
#include <string.h>
using namespace std;

template<class T, class Key, class Compare = std::less<Key> >
class AVLNode {
public:
	Key key;
	T data;
	int height;
	AVLNode<T, Key, Compare>* left;
	AVLNode<T, Key, Compare>* right;
	AVLNode<T, Key, Compare>* parent;

	/*
	 * AVLNode- a constructor that creates a new AVLNode receiving its key,data,
	 * and pointers to its
	 * son (if there is any) and to the parent (unless this is the root).
	 * The constructor dinamically allocate memory for the key and data.
	 */
	AVLNode(const Key& key, const T& data, AVLNode<T, Key, Compare>* left,
			AVLNode<T, Key, Compare>* right, AVLNode<T, Key, Compare>* parent) :
			key(key), data(data), height(0), left(left), right(right), parent(
					parent) {
		/*
		 * AVLNode- an other constructor ,receiving only the height of the Node
		 * (for building and empty tree).
		 */
	}
	AVLNode(const Key& key, const T& data) :
			key((key)), data((data)), height(0), left(NULL), right(NULL), parent(
			NULL) {
	}
	AVLNode(int height) :
			key(), data(), height(height), left(NULL), right(NULL), parent(NULL) {
	}
	AVLNode(int height, AVLNode<T, Key, Compare>* parent) :
			key(), data(), height(height), left(NULL), right(NULL), parent(
					parent) {
	}

	AVLNode(const AVLNode<T, Key, Compare>& other) :
			key(other.key), data(other.data), height(other.height), left(NULL), right(
			NULL), parent(NULL) {
		if (other.left != NULL) {
			left = new AVLNode<T, Key, Compare>(other.left);
			left->parent = this;
		}
		if (other.right != NULL) {
			right = new AVLNode<T, Key, Compare>(other.right);
			right->parent = this;
		}
	}
	AVLNode& operator=(const AVLNode<T, Key, Compare>& other) {
		if (this != &other) {
			AVLNode<T, Key, Compare>* previousLeft = left;
			left = new AVLNode(other.left);
			if (previousLeft != NULL)
				delete previousLeft;
			AVLNode<T, Key, Compare>* previousRight = right;
			left = new AVLNode(other.right);
			if (previousRight != NULL)
				delete previousRight;
		}
		return *this;
	}

	/*
	 *AVLNode ~AVLNode-The destructor of a single AVLNode. deletes the memory that was allocated
	 * in the construction.
	 * */
	/*
	 *
	 *
	 *AVLNode setKey- In case the Node was Empty sets a new key value by
	 * dynamic allocation.
	 */
	void setKey(const Key& new_key) {
		key = (new_key);
	}
	/*
	 *AVLNode setData- In case the Node was Empty sets a new key value by
	 * dynamic allocation.
	 * */
	void setData(const T& new_data) {
		data = (new_data);
	}
	/*
	 * AVLNode getKey- returns a pointer to the key by reference.
	 */

	Key& getKey() {
		return key;
	}
	/*
	 * AVLNode getData- returns a pointer to the data by reference.
	 */

	T& getData() {
		return data;
	}
	/*
	 * AVLNode getHeight- returns the height of the tree
	 */
	int getHeight() {
		return height;
	}
	/*
	 * AVLNode updateHeight- updates the height of the tree asuming his sons
	 * heights are correct.
	 */
	int updateHeight() {
		int leftHeight = (left == NULL ? -1 : left->getHeight());
		int rightHeight = (right == NULL ? -1 : right->getHeight());
		height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
		return height;
	}
	/*
	 * AVLNode updateAllHeights- updates the height of a single Node and then all
	 * of its parents untill the root
	 * the function returns the height of the node received.*/

	int updateAllHeights() {
		AVLNode<T, Key, Compare>* node = this;
		node->updateHeight();
		while (node->parent != NULL) {
			node = node->parent;
			node->updateHeight();
		}
		return this->height;
	}
	/*
	 * AVLNode isLeaf- checks whether
	 */
	AVLNode<T, Key, Compare>* getLeftSon() {
		return left;
	}
	AVLNode<T, Key, Compare>* getRightSon() {
		return right;
	}

	bool isLeaf() {
		if ((getLeftSon() == NULL) && (getRightSon() == NULL))
			return true;
		return false;
	}
	bool hasOnlyChild() {
		if (((getLeftSon() == NULL || (getRightSon() == NULL)) && !isLeaf())) {
			return true;
		}
		return false;
	}
	bool hasTwoChilds() {
		if (!isLeaf() && !hasOnlyChild())
			return true;
		return false;
	}
	bool isLeftSon() {
		if (parent == NULL)
			return false;
		if (parent->left == this) {
			return true;
		}
		return false;
	}
	bool isRightSon() {
		if (parent == NULL)
			return false;
		if (parent->right == this) {
			return true;
		}
		return false;
	}

	int getBalance() {
		if ((this == NULL) || (height == 0)
				|| (this->left == NULL && this->right == NULL))
			return 0;
		if (this->left == NULL)
			return -(this->right->getHeight()) - 1;
		if (this->right == NULL)
			return (this->left->getHeight()) + 1;
		return this->left->getHeight() - this->right->getHeight();
	}
	bool isBalanced() {
		if (this->getBalance() <= 1 && this->getBalance() >= -1)
			return true;
		return false;
	}
	void cleanTreeNodes() {

	}
	/*bool operator< (BinaryNode<T,Key,Compare>* &other) {
	 Compare compare;
	 return compare(*this,other);
	 };*/

};
//=================================================================================================
template<class T, class Key, class Compare = std::less<Key> >
class AVLTree {

public:

	Key most_powerful_student;
	/*
	 * AVLTree- The constructor of the tree.
	 */
	AVLTree() :
			most_powerful_student(), root(NULL), size(0) {

	}
	;
	/*
	 * ~AVLTree- The destructor of the tree. uses an auxilary recursive
	 * function.
	 */
	~AVLTree() {
		destroyTree(root);
	}
	/*
	 * AVLTree getMin- returns the data of the node with the smallest key.
	 */

	T getMin() const {
		if (isEmpty())
			return T();
		return (min(root)->data);
	}
	/*
	 * AVLTree getMax- returns the data of the node with the highest key.
	 */

	Key getMax() {
		if (isEmpty())
			return Key();
		return (max(root)->key);
	}
	/*
	 * AVLTree getSize- returns the number of nodes currently in the tree.
	 */

	int getSize() const {
		return size;
	}
	/*
	 * AVLTree insert- insert an element into the tree and make sure it
	 * keeps the AVL tree rules implemented.
	 */

	void insert(const Key& key, const T& data) {
		if (contains(key))
			return;
		//*** we compare and ifff se
		Compare compare;
		if (compare(most_powerful_student, key)) {
			most_powerful_student = key;
		}
		AVLNode<T, Key, Compare>* new_node = rec_insert(key, data, root);
		size++;
		while (new_node->parent != NULL) {

			new_node = new_node->parent;
			int prevHeight = new_node->height;
			new_node->updateHeight();
			if (new_node->height == prevHeight)
				break;
			if (new_node->isBalanced())
				continue;
			else {
				fixBalance(new_node);
			}
		}
		return;
	}
	/*
	 * AVLTree remove- remove an element form the tree and make sure
	 * the AVL tree rules are implemented.
	 */
	void remove(const Key& key) {
		AVLNode<T, Key, Compare>* to_remove = rec_find(key, root);
		if (to_remove == NULL)
			return;
		//********
//		if (getSize() == 1) {
//			most_powerful_student = Key();
//		} else {
//			Compare compare;
//			if (!compare(key, most_powerful_student)) {
//
//				if (to_remove->left != NULL) {
//					most_powerful_student = to_remove->left->key;
//				} else {
//					most_powerful_student = to_remove->parent->key;
//
//				}
//
//			}
//		}

		AVLNode<T, Key, Compare>* new_parent;
		/// the function has different cases for wether a node is a leaf/
		///has single son/ has two sons.
		if (to_remove->left == NULL && to_remove->right == NULL) {
			new_parent = removeLeaf(to_remove);
		} else {
			if (to_remove->left == NULL || to_remove->right == NULL) {
				new_parent = removeSingleSon(to_remove);
			} else {
				new_parent = removeTwoSons(to_remove);
			}
		}
		size--;
		if (new_parent == NULL)
			return;
		///checking al the nodes in the root for the node removes if they
		//need a balance.
		new_parent->updateAllHeights();
		while (new_parent) {
			if (!new_parent->isBalanced()) {
				fixBalance(new_parent);
			}
			new_parent = new_parent->parent;
		}
		if (getSize() == 0) {
			most_powerful_student = Key();
		}
		else{
			most_powerful_student=getMax();
		}

	}
	/*
	 * AVLTree contains -check if the element exist in the tree
	 */

	bool contains(const Key& key) const {
		if (isEmpty())
			return false;
		AVLNode<T, Key, Compare>* node = rec_find(key, root);
		return (node == NULL ? false : true);
	}
	T* find(const Key& key) const {
		AVLNode<T, Key, Compare>* node = rec_find(key, root);
		if (node == NULL)
			return NULL;
		return &(node->data);
	}

	/*
	 * AVLTree InOrder- receives a function object, goes through every node
	 * in the tree by key value and preforms the function on every data in
	 * the tree.
	 */
	template<class Function>
	void InOrder(Function& f) {
		InOrder_rec(f, root);
	}
	/*
	 * AVLTree InOrderByKey- receives a function object, goes through every node
	 * in the tree by key value and preforms the function on every key in
	 * the tree.
	 */

	template<class Function>
	void InOrderByKey(Function& f) {
		InOrder_rec_by_key(f, root);
	}
	/*
	 * AVLTree InOrderByNode- receives a function object, goes through every node
	 * in the tree by key value and preform the function on every node in
	 * the tree.
	 */

	template<class Function>
	void InOrderByNode(Function& f) {
		InOrder_rec_by_node(f, root);
	}

	/*
	 * AVLTree clean- removes all the nodes in the tree but not destructing
	 * the tree itself. needed for creating an empty tree.
	 */
	void clean() {

		destroyTree(root);
		root = NULL;
		size = 0;
	}

	void cleanAllButRoot() {
		destroyTree(root->left);
		destroyTree(root->right);
		size = 1;
	}

	bool isEmpty() const {
		if (getSize() == 0)
			return true;
		return false;
	}

	void createTreeOfSize(int size) {
		int height = log2(size + 1);
		createFullTree(height);
		int* nodesToRemove = new int(pow(2, (height + 1)) - 1 - size);
		removeExtraNodes(nodesToRemove);
		delete nodesToRemove;
		setSize(size);
	}

	void DeleteTreeData() {
		DeleteTreeData_rec(root);
	}

protected:

	void setSize(int new_size) {
		this->size = new_size;
	}

	void createFullTree(int height) {
		root = new AVLNode<T, Key, Compare>(height);

		createFullTreeAux(height - 1, root);
	}

	void createFullTreeAux(int height, AVLNode<T, Key, Compare>* node) {
		if (height < 0)
			return;
		if (node != root && node->parent->left == node) {
			node->left = new AVLNode<T, Key, Compare>(height,
					node->parent->left);
			node->right = new AVLNode<T, Key, Compare>(height,
					node->parent->left);
		}
		if (node != root && node->parent->right == node) {
			node->left = new AVLNode<T, Key, Compare>(height,
					node->parent->right);
			node->right = new AVLNode<T, Key, Compare>(height,
					node->parent->right);
		}
		if (node == root) {
			node->left = new AVLNode<T, Key, Compare>(height, root);
			node->right = new AVLNode<T, Key, Compare>(height, root);
		}
		createFullTreeAux(height - 1, node->left);
		createFullTreeAux(height - 1, node->right);
	}

	void removeExtraNodes(int *nodesToRemove) {
		if (nodesToRemove <= 0)
			return;
		removeExtraNodesAux(nodesToRemove, root);
	}

	void removeExtraNodesAux(int *nodesToRemove,
			AVLNode<T, Key, Compare>* node) {
		if (node == NULL)
			return;
		int oldNodesToRemoveNum = *nodesToRemove;
		removeExtraNodesAux(nodesToRemove, node->right);
		if (*nodesToRemove > 0) {
			removeExtraNodesAux(nodesToRemove, node->right);
		}
		if (*nodesToRemove > 0) {
			removeExtraNodesAux(nodesToRemove, node->left);
		}
		// incase we havent deletes so far more than 2 nodes.
		if (oldNodesToRemoveNum - 2 < *nodesToRemove) {
			if (*nodesToRemove > 0 && node->isLeaf()) {
				if (node->parent != NULL && node->isLeftSon()) {
					node->parent->left = NULL;
				}
				if (node->parent != NULL && node->isRightSon()) {
					node->parent->right = NULL;
				}
				delete node;
				(*nodesToRemove)--;
			}
		} else {
			node->height--;
		}

	}

	AVLNode<T, Key, Compare>* root;
	int size;

	AVLNode<T, Key, Compare> *min(AVLNode<T, Key, Compare> *node) const {
		if (node == NULL)
			return NULL;
		while (node->left != NULL) {
			node = node->left;
		}
		return node;
	}

	AVLNode<T, Key, Compare> *max(AVLNode<T, Key, Compare> *node) const {
		while (node->right != NULL) {
			node = node->right;
		}
		return node;
	}

	AVLNode<T, Key, Compare>* rec_insert(const Key& key, const T& data,
			AVLNode<T, Key, Compare>* node) {
		Compare compare;
		if (isEmpty()) {
			root = new AVLNode<T, Key, Compare>(key, data, NULL, NULL, NULL);
			return root;
		}
		if (compare(key, node->key)) {
			if (node->left == NULL) {
				node->left = new AVLNode<T, Key, Compare>(key, data, NULL, NULL,
						node);
				return node->left;
			}
			return rec_insert(key, data, node->left);
		}
		if (compare((node->key), key)) {
			if (node->right == NULL) {
				node->right = new AVLNode<T, Key, Compare>(key, data, NULL,
				NULL, node);
				return node->right;
			}
			return rec_insert(key, data, node->right);
		}
		return NULL;
	}

	AVLNode<T, Key, Compare> *removeLeaf(AVLNode<T, Key, Compare> *to_remove) {

		if (to_remove == root) {
			delete root;
			root = NULL;
			return NULL;
		}

		AVLNode<T, Key, Compare>* parent = to_remove->parent;
		if (to_remove == parent->left && to_remove != NULL) {
			delete (parent->left);
			parent->left = NULL;
		}
		if (to_remove == parent->right && to_remove != NULL) {
			delete (parent->right);
			parent->right = NULL;
		}

		return parent;
	}

	AVLNode<T, Key, Compare> *removeSingleSon(
			AVLNode<T, Key, Compare> *to_remove) {

		if (root == to_remove && to_remove != NULL) {
			if (to_remove->right == NULL) {
				root->left->parent = NULL;
				this->root = this->root->left;
			}
			if (to_remove->left == NULL && to_remove != NULL) {
				root->right->parent = NULL;
				this->root = this->root->right;
			}
			delete to_remove;
			return NULL;
		}

		AVLNode<T, Key, Compare>* parent = to_remove->parent;
		if (to_remove->isLeftSon()) {
			if (to_remove->left == NULL) {
				parent->left = to_remove->right;
				to_remove->right->parent = parent;
			} else {
				parent->left = to_remove->left;
				to_remove->left->parent = parent;
			}
		}
		if (to_remove->isRightSon()) {
			if (to_remove->left == NULL) {
				parent->right = to_remove->right;
				to_remove->right->parent = parent;
			} else {
				parent->right = to_remove->left;
				to_remove->left->parent = parent;
			}
		}
		delete to_remove;
		return parent;
	}

	AVLNode<T, Key, Compare> *removeTwoSons(
			AVLNode<T, Key, Compare> *to_remove) {
		AVLNode<T, Key, Compare>* nextVal = to_remove->right;
		nextVal = min(nextVal);
		if (to_remove == root) {
			root->data = nextVal->data;
			root->key = nextVal->key;
		} else {
			to_remove->key = nextVal->key;
			to_remove->data = nextVal->data;
		}
		if (nextVal->isLeaf()) {
			return removeLeaf(nextVal);
		} else
			return removeSingleSon(nextVal);
	}

	AVLNode<T, Key, Compare>* rec_find(const Key& key,
			AVLNode<T, Key, Compare>* node) const {
		if (node == NULL) {
			return NULL;
		}
		Compare compare;
		if (!compare(node->key, key) && !compare(key, node->key)) {
			return node;
		}
		if (compare(key, node->key)) {
			return rec_find(key, node->left);
		} else
			return rec_find(key, node->right);
	}

	void destroyTree(AVLNode<T, Key, Compare>* node) {
		if (node != NULL) {
			destroyTree(node->left);
			destroyTree(node->right);
			delete node;
		}
		return;
	}

	void fixBalance(AVLNode<T, Key, Compare>* node) {
		int balance = node->getBalance();
		if (balance == 2) {
			if (node->left->getBalance() >= 0) {
				node = rotateLL(node);
			}
			if (node->left->getBalance() == -1) {
				node = rotateLR(node);
			}
		}
		if (balance == -2) {
			if (node->right->getBalance() <= 0) {
				node = rotateRR(node);
			}
			if (node->right->getBalance() == 1) {
				node = rotateRL(node);
			}
		}
	}

	AVLNode<T, Key, Compare> *rotateLL(AVLNode<T, Key, Compare> *b) {
		bool isLeftSon = b->isLeftSon();
		AVLNode<T, Key, Compare>* a = b->left;
		b->left = a->right;
		a->parent = b->parent;
		if (b->left != NULL) {
			b->left->parent = b;
		}
		a->right = b;
		b->parent = a;
		if (a->parent != NULL) {
			if (isLeftSon) {
				a->parent->left = a;
			} else
				a->parent->right = a;
		} else {
			root = a;
		}
		b->updateHeight();
		a->updateHeight();
		return a;
	}

	AVLNode<T, Key, Compare> *rotateLR(AVLNode<T, Key, Compare> *b) {
		b->left = rotateRR(b->left);
		return rotateLL(b);

	}

	AVLNode<T, Key, Compare> *rotateRR(AVLNode<T, Key, Compare> *b) {
		bool isLeftSon = b->isLeftSon();
		AVLNode<T, Key, Compare>* a = b->right;
		b->right = a->left;
		a->parent = b->parent;
		if (b->right != NULL) {
			b->right->parent = b;
		}
		a->left = b;
		b->parent = a;
		if (a->parent != NULL) {
			if (isLeftSon) {
				a->parent->left = a;
			} else
				a->parent->right = a;
		} else {
			root = a;
		}
		a->updateHeight();
		b->updateHeight();
		return a;
	}

	AVLNode<T, Key, Compare> *rotateRL(AVLNode<T, Key, Compare> *b) {
		b->right = rotateLL(b->right);
		return rotateRR(b);
	}

	template<class Function>
	void InOrder_rec(Function& f, AVLNode<T, Key, Compare>* node) {
		if (node != NULL) {
			InOrder_rec(f, node->left);
			f(node->data);
			InOrder_rec(f, node->right);
		}
	}

	template<class Function>
	void InOrder_rec_by_key(Function& f, AVLNode<T, Key, Compare>* node) {
		if (node != NULL) {
			InOrder_rec_by_key(f, node->left);
			f(node->key);
			InOrder_rec_by_key(f, node->right);
		}
	}

	template<class Function>
	void InOrder_rec_by_node(Function& f, AVLNode<T, Key, Compare>* node) {
		if (node != NULL) {
			InOrder_rec_by_node(f, node->left);
			f(node);
			InOrder_rec_by_node(f, node->right);
		}
	}

	template<class Function>
	void InOrder_removalrec(Function& f, AVLNode<T, Key, Compare>* node) {
		if (node != NULL) {
			InOrder_removalrec(f, node->left);
			InOrder_removalrec(f, node->right);
			f(node->data);
		}
	}

	void DeleteTreeData_rec(AVLNode<T, Key, Compare>* node) {
		if (node != NULL) {
			DeleteTreeData_rec(node->left);
			DeleteTreeData_rec(node->right);
			delete node->data;
		}
	}

}
;
#endif /* AVLTREE2_H_ */

