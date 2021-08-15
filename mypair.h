#pragma once

#include <iostream>

template <class T, class U>
class mypair {
public:
	T first;
	U second;
	mypair();
	mypair(T first, U second);
	mypair(const mypair& p);
	mypair& operator=(const mypair& p);
	/*friend class mymap;*/
};

template <class T, class U>
mypair<T, U>::mypair() { first = T(); second = U(); }

template <class T, class U>
mypair<T, U>::mypair(T first, U second) { this->first = first;  this->second = second; }

template <class T, class U>
mypair<T, U>::mypair(const mypair& p) { first = p.first; second = p.second; }

template <class T, class U>
mypair<T, U>& mypair<T, U>::operator=(const mypair& p) {
	if (&p == this) {
		return *this;
	}
	first = p.first;
	second = p.second;
	return *this;
}