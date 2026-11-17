#ifndef _STACK_H_
#define _STACK_H_

template<typename T>

class Stack {
	public:
		void clear();
		bool push(const T item);
		bool pop(T &item);
		bool top(T &item);
		bool isEmpty();
		bool isFull();
};

#endif//!_STACK_H_