#include <iostream>
using namespace std;

struct Record {
	int PrimaryKey;
	int Key;
};

void swap(Record &a, Record &b) {
	Record temp = a;
	a = b;
	b = temp;
}

void heapify(Record arr[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left].PrimaryKey > arr[largest].PrimaryKey)
		largest = left;

	if (right < n && arr[right].PrimaryKey > arr[largest].PrimaryKey)
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(Record arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int size;
	cin >> size;

	Record *records = new Record[size];
	for (int i = 0; i < size; i++) {
		cin >> records[i].PrimaryKey >> records[i].Key;
	}

	heapSort(records, size);

	for (int i = 0; i < size; i++) {
		cout << records[i].PrimaryKey << " " << records[i].Key << "\n";
	}

	delete[] records;
	return 0;
}