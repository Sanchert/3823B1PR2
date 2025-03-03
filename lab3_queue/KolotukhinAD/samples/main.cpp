#include <iostream>
#include <string>
#include "priority_queue.h"

using namespace std;

int main()
{
	TPriorityQueue<string> queue;
	
	Pair<string> a = {",", 1};
	Pair<string> b = {" ", 2};
	Pair<string> c = {"Hello", 0};
	Pair<string> d = {"World!", 3};
	
	queue.push(a);
	queue.push(b);
	queue.push(c);
	queue.push(d);
	
	cout << queue << endl;
}