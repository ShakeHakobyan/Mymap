#pragma once
#include <iostream>
#include "mypair.h"

template <class T, class U>
class mymap {
private:
	int _size;
	mypair<T, U>* _arr;
	int _count;
	void resize(const int k);
	void shifttoright(const int idx);
	void shifttoleft(const int idx);
	int getidx(const T first);
public:
	mymap<T, U>();
	mymap(unsigned int size);
	~mymap();
	mymap& operator= (const mymap& mp);
	U& operator[] (const T first);
	mypair<T, U>* add(const mypair<T, U> p);
	mypair<T, U>* add(const T first, const U second);
	mypair<T, U>* get(const T first);
	void erase(const T first);
	void clear();
	bool empty();
	int size();
	int max_size();
	void print();
};

template <class T, class U>
mymap<T, U>::mymap() {
	_size = 1;
	_arr = new mypair<T, U>[_size];
	_count = 0;
}

template <class T, class U>
mymap<T, U>::mymap(unsigned int size) {
	if (size == 0) {
		++size;
	}
	_size = size;
	_arr = new mypair<T, U>[_size];
	_count = 0;
}

template <class T, class U>
mymap<T, U>::~mymap() {
	delete[] _arr;
}

template <class T, class U>
mymap<T, U>& mymap<T, U>::operator=(const mymap& mp) {
	if (&mp == this) {
		return *this;
	}

	if (mp._count > this->_size) {
		resize(mp._count - this->_size);
	}

	for (int i = 0; i < mp._count; ++i) {
		this->_arr[i] = mp._arr[i];
		++_count;
	}
	return *this;
}

template <class T, class U>
U& mymap<T, U>::operator[](const T first) {
	if (getidx(first) == -1) {
		return add(first, T())->second;
	}
	return get(first)->second;
}

template <class T, class U>
mypair<T, U>* mymap<T, U>::add(const mypair<T, U> p) {

	if (_count == _size) {
		resize(1);
	}

	if (_count == 0) {
		_arr[0] = p;
		++_count;
		return _arr;
	}

	if (p.first < _arr[0].first) {
		shifttoright(0);
		_arr[0] = p;
		++_count;
		return _arr;
	}
	if (p.first > _arr[_count - 1].first) {
		_arr[_count] = p;
		++_count;
		return _arr + _count - 1;
	}
	int r = _count - 1;
	int l = 0;
	while (1) {
		int i = (r + l) / 2;
		if (p.first == _arr[i].first) {
			_arr[i].second = p.second;
			return _arr + i;
		}
		if (p.first > _arr[i].first && p.first < _arr[i + 1].first) {
			shifttoright(i + 1);
			_arr[i + 1] = p;
			++_count;
			return _arr + i + 1;
		}
		if (p.first < _arr[i].first) {
			r = i - 1;
		}
		else {
			l = i + 1;
		}
	}
}

template <class T, class U>
mypair<T, U>* mymap<T, U>::add(const T first, const U second) {
	mypair<T, U> p(first, second);
	return add(p);
}

template <class T, class U>
mypair<T, U>* mymap<T, U>::get(const T first) {
	return ((getidx(first) != -1) ? (_arr + getidx(first)) : nullptr);
}

template<class T, class U>
void mymap<T, U>::erase(const T first) {
	if (getidx(first) != -1) {
		shifttoleft(getidx(first));
		--_count;
	}
}

template <class T, class U>
void mymap<T, U>::clear() {
	delete[] _arr;
	_size = 1;
	_arr = new mypair<T, U>[_size];
	_count = 0;
}

template <class T, class U>
bool mymap<T, U>::empty() { return !_count; }

template <class T, class U>
int mymap<T, U>::size() { return _count; }

template <class T, class U>
int mymap<T, U>::max_size() { return _size; }

template <class T, class U>
void mymap<T, U>::print() {
	for (int i = 0; i < _count; ++i) {
		std::cout << _arr[i].first << " : " << _arr[i].second << std::endl;
	}
}

template <class T, class U>
void mymap<T, U>::resize(const int k) {
	_size += k;
	mypair<T, U>* tmp = new mypair<T, U>[_size];
	for (int i = 0; i < _count; ++i) {
		tmp[i] = _arr[i];
	}
	delete[] _arr;
	_arr = tmp;
}

template <class T, class U>
void mymap<T, U>::shifttoright(const int idx) {
	for (int i = _count - 1; i >= idx; --i) {
		_arr[i + 1] = _arr[i];
	}
}

template <class T, class U>
void mymap<T, U>::shifttoleft(const int idx) {
	for (int i = idx; i < _count; ++i) {
		_arr[i] = _arr[i + 1];
	}
}

template <class T, class U>
int mymap<T, U>::getidx(const T first) {
	int r = _count - 1;
	int l = 0;
	while (r >= l) {
		if (first == _arr[(r + l) / 2].first) {
			return ((r + l) / 2);
		}
		if (first < _arr[(r + l) / 2].first) {
			r = (r + l) / 2 - 1;
		}
		else {
			l = (r + l) / 2 + 1;
		}
	}
	return -1;
}

