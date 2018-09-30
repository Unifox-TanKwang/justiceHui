#include "vector.h"
#include "stack.h"
#include "list.h"
#include "queue.h"
#include <iostream>
using namespace JH;

int main(){
	//test vector
	std::cout << "[[vector]]\n";
	vector<int> v(6, 5);
	std::cout << "asdf";
	for(int i=0; i<v.size(); i++){
		std::cout << v[i] << std::ends;
	}std::cout << std::endl;
	v.resize(10); std::cout << v.size() << std::ends << v.capacity() << std::endl;
	v.clear(); std::cout << v.size() << std::ends << v.capacity() << std::endl;
	for(int i=1; i<=20; i++){
		v.push_back(i);
	}
	std::cout << v.size() << std::ends << v.capacity() << std::endl;
	for(int i=1; i<=10; i++){
		v.pop_back();
	}
	std::cout << v.size() << std::ends << v.capacity() << std::endl;
	while(!v.empty()) v.pop_back();
	std::cout << v.size() << std::ends << v.capacity() << std::endl;
	
	//test stack
	std::cout << "[[stack]]\n";
	stack<int> s;
	s.push(1);
	s.push(2);
	std::cout << s.top() << std::endl;
	std::cout << s.size() << std::endl;
	std::cout << s.empty() << std::endl;
	s.pop(); s.pop(); s.pop();
	std::cout << s.size() << std::endl;
	std::cout << s.empty() << std::endl;
	s.pop();
	s.push(3);
	std::cout << s.empty() << std::endl;
	std::cout << s.top() << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "[[stack_list]]\n";
	stack_list<int> s1;
	s1.push(1);
	s1.push(2);
	std::cout << s1.top() << std::endl;
	std::cout << s1.size() << std::endl;
	std::cout << s1.empty() << std::endl;
	s1.pop(); s1.pop(); s1.pop();
	std::cout << s1.size() << std::endl;
	std::cout << s1.empty() << std::endl;
	s1.pop();
	s1.push(3);
	std::cout << s1.empty() << std::endl;
	std::cout << s1.top() << std::endl;
	 
	//test list
	std::cout << "[[list]]\n";
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(5);
	l.push_front(0);
	l.insert(3, 3);
	l.insert(4, 4);
	
	l.print();
	std::cout << std::endl;
	l.erase(4);
	l.print();
	std::cout << std::endl;
	l.pop_back();
	l.print();
	
	std::cout << std::endl << l.size() << std::endl;
	
	//test queue
	std::cout << "[[queue]]\n";
	queue<int> q;
	std::cout << "adf\n";
	q.push(1); q.push(2);
	std::cout << q.front() << std::endl;
	std::cout << q.back() << std::endl;
	std::cout << q.size() << std::endl;
	std::cout << q.empty() << std::endl;
	if(!q.empty()) q.pop();
	if(!q.empty()) q.pop();
	if(!q.empty()) q.pop();
	std::cout << q.size() << std::endl;
	std::cout << q.empty() << std::endl;
	if(!q.empty()) q.pop();
	q.push(3);
	std::cout << q.empty() << std::endl;
	std::cout << q.front() << std::endl;
}
