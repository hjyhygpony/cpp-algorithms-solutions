#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>

template<typename T>

class List {
		void clear();
		bool isEmpty();
		bool append(const T value);
		bool insert(const int p, const T value);
		bool deleteMethod(const int p);
		bool getValue(const int p, T &value);
		bool setValue(const int p, const T value);
		bool getPos(int &p, const T value); //¼ìË÷
};

#endif//!_LIST_H_