#include "List.h"
#include <iostream>

using namespace std;

template <typename T>

class arrList: public List<T> {
	private:
		T *aList;
		int maxSize;
		int curLen;
		int position;
	public:
		arrList(const int size) {
			maxSize = size;
			aList = new T[maxSize];
			curLen = position = 0;
		}
		~arrList() {
			delete[]aList;
		}
		void clear() {
			delete[]aList;
			curLen = position = 0;
			aList = new T[maxSize];
		}
		int length() {
			return curLen;
		};

		bool append(const T value) {
			if (curLen >= maxSize) {
				cout << "顺序表已满，无法追加" << endl;
				return false;
			}
			aList[curLen++] = value;
			return true;
		};
		bool setValue(const int p, const T value) {
			if (p < 0 || p >= curLen) {
				cout << "设值位置非法" << endl;
				return false;
			}
			aList[p] = value;
			return true;
		};
		bool getValue(const int p, T &value) {
			if (p < 0 || p >= curLen) {
				cout << "寻值位置非法" << endl;
				return false;
			}
			value = aList[p];
			return true;
		};
		bool getPos(int &p, const T value);
		bool insert(const int p, const T value);
		bool deleteMethod (const int p);



};

template<typename T>

bool arrList<T>::getPos(int &p, const T value) {
	//i<maxSize浪费了，开多大不一定存多大
	for (int i = 0; i < curLen ; i++) {
		if (value == aList[i]) {
			p = i;
			return true;
		}
	}
	return false;
}

template<typename T>

bool arrList<T>::insert(const int p, const T value) {
	int i;
	if (curLen >= maxSize) {
		cout << "顺序表溢出" << endl;
		return false;
	}
	if (p < 0 || p > curLen) {
		cout << "插入位置非法" << endl;
		return false;
	}
	for (i = curLen; i > p; i--) {
		aList[i] = aList[i - 1];
	}
	aList[p] = value;
	curLen++;
	return true;
}

template<typename T>

bool arrList<T>::deleteMethod(const int p) {
	int i;
	if (curLen <= 0) {
		cout << "顺序表为空" << endl;
		return false;
	}
	if (p < 0 || p > curLen - 1) {
		cout << "删除位置非法" << endl;
		return false;
	}
	for (i = p; i < curLen - 1; i++) {
		aList[i] = aList[i + 1];
	}
	curLen--;
	return true;
}


int main() {
	arrList<int> list(10);  // 创建一个容量为10的顺序表

    // 测试追加
    for (int i = 0; i < 5; i++) {
        list.append(i * 10);
    }

    // 测试插入
    list.insert(2, 25);

    // 测试删除
    list.deleteMethod(3);

    // 测试获取值
    int value;
    if (list.getValue(2, value)) {
        cout << "位置2的值为: " << value << endl;
    }

    // 测试设置值
    list.setValue(2, 99);

    // 测试查找位置
    int pos;
    if (list.getPos(pos, 99)) {
        cout << "值99的位置为: " << pos << endl;
    }

    // 测试长度
    cout << "当前表的长度为: " << list.length() << endl;

    // 清空表
    list.clear();
    cout << "清空后表的长度为: " << list.length() << endl;

	return 0;
}

