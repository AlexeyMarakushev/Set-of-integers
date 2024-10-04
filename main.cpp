#include "set.h"
int main() {
	set A;
	if(A.test_set()){
		std::cout << "OK";
		return 0;
	}
	else{
		return -1;
	}
}