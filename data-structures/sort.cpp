//直接插入
template<class Record>

void InsertSort(Record Array[], int n) {
	Record TempRecord;
	int i, j;
	for (int i = 1; i < n; i++) {
		TempRecord = Array[i];
		while (j >= 0 && TempRecord < Array[j]) {
			Array[j + 1] = Array[j];
			j = j - 1;
		}
		Array[j + 1] = TempRecord;
	}
}

//Shell
template<class Record>

void ShellSort(Record Array[], int n) {
	int i, delta;
	for (delta = n / 2; delta > 0; delta /= 2) {
		for (i = 0; i < delta; i++) {
			ModInsSort(&Array[i], n - i, delta);
		}
		ModInsSort(&Array[i], n, 1);
	}
}

template<class Record>

void ModInsSort(Record Array[], int n, int delta) {
	int i, j;
	for (i = delta; i < n; i += delta) {
		for (j = i; j >= delta; j -= delta) {
			if (Array[j] < Array[j - delta]) {
				swap(Array, j, j - delta);
			} else
				break;
		}
	}
}

//直接选择
template<class Record>

void SelectSort(Record Array[], int n) {
	int i, j, Smallest;
	for (i = 0; i < n - 1; i++) {
		Smallest = i;
		for (j = i + 1; j < n; j++) {
			if (Array[j] < Array[Smallest]) {
				Smallest = j;
			}
			swap(Array, i, Smallest);
		}
	}
}

//堆排序
template<class Record>

void Heapsort(Record Array[], int n) {
	int i;
	MaxHeap<Record>max_heap = MaxHeap<Record>(Array, n, n);
	for (i = 0; i < n - 1; i++) {
		max_heap.RemoveMax();
	}
}

//冒泡
template<class Record>

void BubbleSort(Record Array[], int n) {
	for (int i = 1; i < n; i++) {
		for (int j = n - 1; j >= i; j--) {
			if (Array[j] < Array[j - 1]) {
				swap(Array, j, j - 1);
			}
		}
	}
}


//优化的冒泡
template<class Record>

void ImprovedBubbleSort(Record Array[], int n) {
	bool NoSwap;
	for (int i = 1; i < n; i++) {
		NoSwap = true;
		for (int j = n - 1; j >= i; j--) {
			if (Array[j] < Array[j - 1]) {
				swap(Array, j, j - 1);
				NoSwap = false;
			}
			if (NoSwap)
				return;
		}
	}

}

//快排
template<class Record>

void QuickSort(Record Array[], int left, int right) {
	if (right <= left)
		return;

	int pivot = SelectPivot(left, right); //选择轴值
	swap(Array, pivot, right); //分割前先把轴值放到数组末端
	pivot = Partition(Array, left, right);
	QuickSort(Array, left, privot - 1);
	QuickSort(Array, privot + 1, right);
}

int SelectPrivot(int left, int right) {
	return (left + right) / 2;
}

template<class Record>

int Partition(Record Array[], int left, int right) {
	Record TempRecord;
	int i = left;
	int j = right;
	TempRecord = Array[j];
	while (i != j) {
		while ((Array[i] <= TempRecord) && (j > i)) { //左指针右移，越过小于等于轴值的记录
			i++;
		}
		if (i < j) { //将逆置元素换到右边的空位，右指针向左移动
			Array[j] = Array[i];
			j--;
		}
		while ((Array[i] >= TempRecord) && (j > i)) { //右指针左移，越过大于等于轴值的记录
			j--;
		}
		if (i < j) { //将逆置元素换到左边的空位，左指针向右移动
			Array[i] = Array[j];
			i++;
		}
	}
	Array[i] = TempRecord;
	return i;
}

//优化的快排
#define THRESHOLD 16
template<class Record>

void ModQuickSort(Record Array[], int left, int right) {
	if (right - left + 1 > THRESHOLD) {
		int pivot = SelectPrivot(left, right);
		swap(Array, pivot, right);
		pivot = Partition(Array, left, right);
		ModQuickSort(Array, left, pivot - 1);
		ModQuickSort(Array, pivot + 1, right);
	}
}

template<class Record>

void QuickSort(Record Array[], int n) {
	ModQuickSort(Array, 0, n - 1);
	InsertSort(Array, n);
}
//归并
template<class Record>
void MergeSort(Record Array[], Record TempArray[], int left, int right)



