#include <iostream>
#include <Stack.h>

template <class T>

class arrStack: public Stack<T> {
	private:
		int mSize;
		int top;
		T *st;
	publice:
		arrStack(int size) {
			mSize = size;
			top = -1;
			st = new T[mSize];
		}
		~arrStack() {
			delete []st;
		}

		void clear() {
			top = -1;
		}

		bool push(const T item) {
			if (top == mSize - 1) {
				cout << "栈满" << endl;
				return false;
			} else {
				top++;
				st[top] = item;
				return true;
			}
		}

		bool autopush(const T item) {
			if (top == mSize - 1) {
				T *newSt = new T[mSize * 2];
				for (int i = 0; i < top; i++) {
					newSt[i] = st[i];
				}
				delete[]st;
				st = newSt;
				mSize *= 2;
			}
			top++;
			st[top] = item;
		}

		bool pop(T &item) {
			if (top == -1) {
				cout << "栈为空，不能执行出栈操作" << endl;
				return false;
			} else {
				item = st[top];
				top--;
				return true;
			}
		}

		bool top(T &item) {
			if (top == -1) {
				cout << "栈为空，不能读取栈顶元素" << endl;
				return false;
			} else {
				item = st[top];
				return true;
			}
		}



};