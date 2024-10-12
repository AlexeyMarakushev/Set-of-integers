#include "set.h"
#include <iostream>
using namespace std;
bool test(){
	int n = 5, m = 5;
	set A{n, new int[n]{1, 2, 3, 4, 5}};
	set B{m, new int[m]{3, 4, 5, 6, 7}};
	cout << A;
	cout << endl;
	cout << B;
	cout << endl;
	cout << (A | B);
	cout << endl;
	A.reset();
	B.reset();
	return true;
}
	