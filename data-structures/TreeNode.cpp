template<class T>

class TreeNode {
	public:
		TreeNode(const T &value);
		virtual ~TreeNode() {
		};

		bool isLeaf();
		T Value();

		TreeNode<T> *LeftMostChild();
		TreeNode<T> *RightSibling();

		void setValue(const T &value);
		void setChild(TreeNode<T> *pointer);
		void setSibling(TreeNode<T> *pointer);

		void InsertFirst(TreeNode<T> *node);
		void InsertNext(TreeNode<T> *node);
};

void TreeNode<T>::InsertFirst(TreeNode<T> *node) { //以第一个子结点的身份插入结点
	if (pChild == NULL) {
		pChild = node;
	} else {
		node->setSibling(pChild);//原来结点有孩子，那就把它作为现在新插入node的兄弟
		pChild = node;
	}
}

void TreeNode<T>::InsertNext(TreeNode<T> *node) { //以右兄弟的身份插入结点
	if (pChild == NULL) {
		pChild = node;
	} else {
		node->setSibling(pSibling);
		pSibling = node;
	}
}