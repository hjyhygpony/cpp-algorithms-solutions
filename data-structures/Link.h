#ifndef _LINK_H_
#define _LINK_H_

#include <iostream>

template<typename T>

class Link {
	public:
		T data;
		Link<T> *next;

		Link(const T info, Link<T> *nextValue = NULL) {
			data = info;
			next = nextValue;
		}

		Link(const Link<T> *nextValue) {
			next = nextValue;
		}
};

#endif//!_LIST_H_