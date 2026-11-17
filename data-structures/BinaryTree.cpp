template<class T>

class BinaryTree {
	private:
		BinaryTreeNode<T> *root;


	public:
		BinaryTree() {
			root = NULL;
		};
		~BinaryTree() {
			DeleteBinaryTree(root);
		};

		bool isEmpty() const;

		BinaryTreeNode<T> *Root() {
			return root;
		}

		BinaryTreeNode<T> *Parent(BinaryTreeNode<T> *current);
		BinaryTreeNode<T> *LeftSibling(BinaryTreeNode<T> *current);
		BinaryTreeNode<T> *RightSibling(BinaryTreeNode<T> *current);

		void CreateTree(const T &info, BinaryTreeNode<T> &leftTree, BinaryTreeNode<T> &rightTree);


		void PreOrder(BinaryTreeNode<T> *root);
		void InOrder(BinaryTreeNode<T> *root);
		void PostOrder(BinaryTreeNode<T> *root);
		void LevelOrder(BinaryTreeNode<T> *root);
		void DeleteBinaryTree(BinaryTreeNode<T> *root);

};

template<class T>

void BinaryTreeNode<T>::PreOrder(BinaryTreeNode<T> *root) {
	if (root != NULL) {
		Visit(root->value());
		PreOrder(root->leftchild());
		PreOrder(root->rightchild());
	}
}

void BinaryTreeNode<T>::InOrder(BinaryTreeNode<T> *root) {
	if (root != NULL) {
		InOrder(root->leftchild());
		Visit(root->value());
		InOrder(root->rightchild());
	}
}

void BinaryTreeNode<T>::PostOrder(BinaryTreeNode<T> *root) {
	if (root != NULL) {
		PostOrder(root->leftchild());
		PostOrder(root->rightchild());
		Visit(root->value());

	}
}

void BinaryTreeNode<T>::LevelOrder(BinaryTreeNode<T> *root) {
	using std::queue;
	queue<BinaryTreeNode<T>*>aQueue;
	BinaryTreeNode<T> *pointer = root;
	if (pointer) {
		aQueue.push(pointer);
	}
	while (!aQueue.empty()) {
		pointer = aQueue.front();
		aQueue.pop();
		Visit(pointer->value());
		if (pointer->leftchildH() != NULL) {
			aQueue.push(pointer->leftchildH());
		}
		if (pointer->rightchildH() != NULL) {
			aQueue.push(pointer->rightchildH());
		}
	}
}

