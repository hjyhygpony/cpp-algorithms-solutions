template<class T>

class MinHeap {
	private:
		T *heapArray;
		int CurrentSize;
		int MaxSize;
		void swap(int pos_x, int pos_y);
		void BuildHeap();

	public:
		MinHeap(const int n);
		virtual ~MinHeap() {
			delete[] heapArray;
		};

		bool isEmpty();

		bool isLeaf(int pos)const;

		int LeftChild(int pos)const;
		int RightChild(int pos)const;
		int Parent(int pos)const;

		bool Remove(int pos, T &node);
		bool Insert(const T &newNode);
		T &RemoveMin();
		void SiftUp(int position);
		void SiftDown(int left);


};

