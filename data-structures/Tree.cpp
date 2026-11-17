template <class T>

class Tree {


	public:
		Tree();
		virtual ~Tree();

		TreeNode<T> *getRoot();
		void CreateRoot(const T &rootValue);

		bool isEmpty();

		TreeNode<T> *



		TreeNode<T> *PrevSibling(TreeNode<T> *current);

};

template<class T>

TreeNode<T> *Tree<T>::PrevSibling(TreeNode<T> *current) {
	using std::queue;
	queue<TreeNode<T>*> aQueue;
	TreeNode<T> *pointer = root;
	TreeNode<T> *prev = NULL;
	if ((current == NULL) || (pointer == NULL) || current == pointer) {
		return NULL;
	}
	while (pointer) {
	}

	while


}

