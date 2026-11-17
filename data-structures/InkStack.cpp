#include <iostream>
#include <Stack.h>

template <class T>

class InkStack: public Stack<T> {
	private:
		Link<T> *top;
		int size;
	public:
		InkStack() : top(nullptr), size(0) {}
		~InkStack() {
			clear();
		}

		void clear() {
			while (top != NULL) {
				Link<T> *tmp = top;
				top = top->next;
				delete tmp;
			}
		}

		bool push(const T item) {
			Link<T> *tmp = new Link<T>(item, top);
			top = tmp;
			size++;
			return true;
		}

		bool pop(T &item) {
			Link<T> *tmp;
			if (size == 0) {
				cout << "栈为空，不能执行出栈操作" << endl;
				return false;
			}
			item = top->data;
			tmp = top->next;
			delete top;
			top = tmp;
			size--;
			return true;

		}
		bool top(T &item) {
			if (size == 0) {
				cout << "栈为空，不能执行出栈操作" << endl;
				return false;
			}
			item = top->data;
			return true;
		};
		bool isEmpty() const {
			return size == 0;
		}
		bool isFull() const {
			return false;
		}


};