template<class T>

class BinaryTreeNode {

		friend class BinaryTree<T>;

	private:
		T info;
		BinaryTreeNode *leftchild, *rightchild;

	public:
		BinaryTreeNode();
		BinaryTreeNode(const T &ele);
		BinaryTreeNode(const T &ele, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r);

		T value() const;
		BinaryTreeNode<T> *leftchildH()const;
		BinaryTreeNode<T> *rightchildH()const;

		void setLeftchild(BinaryTreeNode<T> *);
		void setRightchild(BinaryTreeNode<T> *);
		void setValue(const T &val);

		bool isLeaf() const;

		BinaryTreeNode<T> &operator=(const BinaryTreeNode<T> &Node);//??





};