#include "Link.h"
#include <iostream>

template<typename T>

class InkList: public Link<T> {
	private:
		Link<T> *head, *tail;
		Link<T> *setPos(const int p);

	public:
		InkList(int s);
		~InkList();

		bool isEmpty();
		void clear();
		int length();
		bool append(const T value);
		bool insert(const int p, const T value);
		bool deleteMethod(const int p);
		bool getValue(const int p, T &value);
		bool getPos(int &p, const T value);
};

template<typename T>

InkList::InkList(int defSIze) {
	head = tail = new Link<T>;
}

template<typename T>

InkList::~InkList() {
	Link<T> *tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
}


template<typename T>

InkList::setPos(int i) {
	int count = 0;
	if (i == -1) {
		return head;
	}
	Link<T> *p = new Link<T>(head->next);
	while (p != NULL && count < i) {
		p = p->next;
		count++;
	}
	return p;
}

template<typename T>

InkList::insert(const int i, const T value) {
	Link<T> *p, *q;
	p = setPos(i - 1);
	if (p == NULL) {
		cout << "illegal insert point" << endl;
		return false;
	}

	q = new Link<T>(value, p->next);
	p->next = q;

	if (p == tail) {
		tail = q;
	}

	return true;

}

template<typename T>

InkList::deleteMethod(const int i) {
	Link<T> *p, *q;
	p = setPos(i - 1);
	if (p == NULL || p == tail) {
		cout << "illegal delete point" << endl;
		return false;
	}

	q = p->next;

	if (q == tail) {
		tail = p;
		p->next = NULL;
		delete q;
	}

	else if (q != NULL) {
		p->next = q->next;
		delete q;
	}

	return true;
}


int main() {
	return 0;
}
