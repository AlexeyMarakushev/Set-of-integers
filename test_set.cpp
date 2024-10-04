#include "set.h"
#include <iostream>
using namespace std;
bool set::test_set(){
	set A;
	set B;
	set C;
	A.card = 3;
	A.members = new int(A.card);
	A.members[0] = 1;
	A.members[1] = 2;
	A.members[2] = 3;
	B.card = 3;
	B.members = new int(B.card);
	B.members[0] = 3;
	B.members[1] = 4;
	B.members[2] = 5;
	C = A | B;
	for(int i = 0; i < A.card + B.card; i++){
		if(i < A.card){
			if(!belonging(C, A.members[i])){
				cout << "error 1" << endl;
				return false;
			}
		}
		else{
			if(!belonging(C, B.members[i - A.card])){
				cout << "error 2" << endl;
				return false;
			}
		}
	}
	if(!(A <= C)){
		cout << "error 3" << endl;
		return false;
	}
	if(!(B <= C)){
		cout << "error 4" << endl;
		return false;
	}
	return true;
}
	