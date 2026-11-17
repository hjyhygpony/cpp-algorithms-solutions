#include <iostream>
//#include <queue>

using namespace std;

template<typename T>

class Link {
	public:
		T data;
		Link<T> *next;
//const?
		Link(const T info, Link<T> *nextValue = NULL) {
			data = info;
			next = nextValue;
		}

		Link(const Link<T> *nextValue) {
			next = nextValue;
		}
};

template<typename T>

class InkQueue {
	private:
		int size;
		Link<T> *front;
		Link<T> *rear;

	public:
		InkQueue() {
			size = 0;
			front = rear = NULL;
		}
		~InkQueue() {
			clear();
		}
		void clear() {
			while (front != NULL) {
				Link<T> *tmp = front;
				front = front->next;
				delete tmp;
			}
			rear = NULL;
			size = 0;
		};
		bool push(const T item) {
			if (rear == NULL) {
				front = rear = new Link<T>(item, NULL);
			} else {
				rear->next = new Link<T>(item, NULL);
				rear = rear->next;
			}
			size++;
			return true;
		};
		bool pop(T &item) {
			Link<T> *tmp;
			if (size == 0) {
				cout << "队列为空" << endl;
				return false;
			}
			item = front->data;
			tmp = front;
			front = front->next;
			delete tmp;
			if (front == NULL) {
				rear = NULL;
			}
			size--;
			return true;
		};
		bool getFront(T &item) {
			if (size == 0) {
				cout << "队列为空" << endl;
				return false;
			}
			item = front->data;
			return true;
		};
		bool empty() {
			return front == NULL;
		};
		bool isFull() {
			return false;
		};
};

int main() {
	int m, n, s;
	cin >> n >> s >> m;
	InkQueue<int> q;

	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}

	int p = 1;
	int t;
	int ul;
	while (p != s) {
		p++;
		q.getFront(t);
		q.push(t);
		q.pop(ul);
	}
	p = 1;
	while (!q.empty()) {

		if (p != m) {
			q.getFront(t);
			q.push(t);
			q.pop(ul);
			p++;
		} else {
			q.getFront(t);
			cout << t << " ";
			q.pop(ul);
			p = 1;
		}
	}


	return 0;
}