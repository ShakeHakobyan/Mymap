#include <iostream>
#include <string>
#include <map>
#include "mypair.h"
#include "mymap.h"

int main() {

	mypair<int, char> p;
	p.first = 5;
	//std::cout << p.second << std::endl;
	mypair<int, float> p1(4, 1.2);
	//std::cout << p1.second << std::endl;
	mypair<int, char> p2 = p;
	p2.first = 15;
	p2.second = 'y';
	//std::cout << p2.first << std::endl;
	
	mymap<int, char> mp1(5);

	mymap<int, char> mp2(1);
	mp1.print();
	mp1.add(p);
	mp1.print();
	mp2 = mp1;
	mp2.print();
	mp2.add(14, 'k');
	mp2.add(p2);
	mp2.add(12, ']');
	mp2.print();
	mypair<int, char>* ptr = mp2.get(12);
	//std::cout << ptr->second << std::endl;
	mp2.erase(12);
	mp2.print();
	mp1.clear();
	mp1.print();
	mp2[10] = '2';
	mp2.print();
	std::cout << mp2[14] << std::endl;
	

	return 0;
}

