#include <iostream>
#include "polinom.h"

using namespace std;

int main()
{
	Polinom p;
	cin >> p;
	cout << p << endl;
	p.reduce();
	cout << p << endl;
	Point point(1, 2, 3);
	cout << p.calculate(point);
	// List<int> l;
	// int action;
	// bool run = true;
	// cout << "1: addBack" << endl;
	// cout << "2: addFront" << endl;
	// cout << "3: addTo" << endl;
	// cout << "4: size" << endl;
	// cout << "5: isEmpty" << endl;
	// cout << "6: print" << endl;
	// while (run) {
	// 	cout << endl << "input action number: ";
	// 	cin >> action;
	// 	int value;
	// 	switch (action)	{
	// 		case 1:
	// 			cin >> value;
	// 			l.pushBack(value);
	// 			break;
	// 		case 2:
	// 			cin >> value;
	// 			l.pushFront(value);
	// 			break;
	// 		case 3:
	// 			int position;
	// 			cin >> position;
	// 			cin >> value;
	// 			l.addTo(position, value);
	// 			break;
	// 		case 4:
	// 			int pos;
	// 			cin >> pos;
	// 			l.removeFrom(pos);
	// 			break;
	// 		case 5:
	// 			cout << l.getSize() << endl;
	// 			break;
	// 		case 6:
	// 			cout << l.isEmpty() << endl;
	// 			break;
	// 		case 7:
	// 			l.print();
	// 			break;
	// 		case 8:
	// 			run = false;
	// 			break;
	// 		default:
	// 			run = false;
	// 			break;
	// 	}
	// }
}
