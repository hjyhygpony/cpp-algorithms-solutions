#include <iostream>
using namespace std;

// 定义栈元素结构体
struct myStack {
	int primaryKey;  // 主关键码
	int key;         // 键码
};

// 交换数组中两个元素的函数模板
template <class Record>

void swap(Record Array[], int i, int j) {
	Record temp = Array[i];
	Array[i] = Array[j];
	Array[j] = temp;
}

// 快速排序函数模板
template <class Record>

void QuickSort(Record Array[], int left, int right) {
	if (right <= left)
		return;  // 如果右边界小于等于左边界，直接返回

	// 选择左边界元素作为基准值
	Record pivotValue = Array[left];

	// 对数组进行分区并获取基准值最终位置
	int pivot = Partition(Array, left, right);

	// 递归排序左半部分
	QuickSort(Array, left, pivot - 1);

	// 递归排序右半部分
	QuickSort(Array, pivot + 1, right);
}

// 分区函数实现
template <class Record>

int Partition(Record Array[], int left, int right) {
	// 首先将基准值(左边界元素)与最右元素交换
	swap(Array, left, right);

	// 基准值现在位于最右位置
	Record TempRecord = Array[right];

	int l = left;   // 左指针从左边开始
	int r = right;  // 右指针从右边开始

	while (l != r) {
		// 左指针向右移动，直到找到大于基准值的元素
		while (Array[l].primaryKey <= TempRecord.primaryKey && r > l)
			l++;

		if (l < r) {
			Array[r] = Array[l];  // 将大于基准值的元素放到右边
			r--;
		}

		// 右指针向左移动，直到找到小于基准值的元素
		while (Array[r].primaryKey >= TempRecord.primaryKey && r > l)
			r--;

		if (l < r) {
			Array[l] = Array[r];  // 将小于基准值的元素放到左边
			l++;
		}
	}

	Array[l] = TempRecord;  // 将基准值放到最终位置
	return l;              // 返回基准值的位置
}

int main() {
	int size;
	cin >> size;  // 输入数组大小

	myStack arr[100001];  // 定义数组

	// 输入数组元素
	for (int i = 0; i < size; i++) {
		cin >> arr[i].primaryKey >> arr[i].key;
	}

	// 调用快速排序
	QuickSort(arr, 0, size - 1);

	// 输出排序结果
	for (int i = 0; i < size; i++) {
		cout << arr[i].primaryKey << " " << arr[i].key << endl;
	}

	return 0;
}