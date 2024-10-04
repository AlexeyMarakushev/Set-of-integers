#include "set.h"
#include <iostream>

set::set(){
    card = 0;
    members = nullptr;
}

set::~set() {
    if(members != nullptr){
        delete[] members;
    }
}

set::set(const set &A){
    card = A.card;
    members = new int[card];
    for(int i = 0; i < card; i++) {
        members[i] = A.members[i]; 
    }
}

set& set::operator=(const set &A){
    if(this != &A) {
        if(members != nullptr){
            delete[] members;
        }
        card = A.card;
        members = new int[card];
        for (int i = 0; i < card; i++) {
            members[i] = A.members[i]; 
        }
    }
    return *this;
}

set set::operator|(const set &A){
	set C;
	int i, j, f, k = 0, q = this->card + A.card;
	for(i = 0; i < this->card; i++){
		for(j = 0; j < A.card; j++){
			if(this->members[i] == A.members[j]){
				q--;
				break;
			}
		}
	}
	C.card = q;
	C.members = new int[C.card];
	for(i = 0; i < A.card; i++){
		C.members[i] = A.members[i];
	}
	for(i = 0; i < this->card; i++){
		f = 0;
		for(j = 0; j < A.card; j++){
			if(this->members[i] == A.members[j]){
				f = 1;
				break;
			}
		}
		if(f == 0){
			C.members[k + A.card] = this->members[i];
			k++;
		}
	}
	return C;
}

set& set::operator|=(const set &other){
	*this = *this | other;
	return *this;
}
bool set::belonging(const set &A, int z){
	for(int i = 0; i < A.card; i++){
		if(z == A.members[i]){
			return true;
		}
	}
	return false;
}

bool set::operator==(const set &A) const{
	int f;
	if(this->card == A.card){
		for(int i = 0; i < A.card; i++){
			f = 0;
			for(int j = 0; j < this->card; j++){
				if(A.members[i] == this->members[j]){
					f = 1;
				}
			}
			if(f != 1){
				return false;
			}
		}
	}
	else{
		return false;
	}
	return true;
}

bool set::operator<=(const set &other) const{
	int f;
	if(this->card <= other.card){
		for(int i = 0; i < this->card; i++){
			f = 0;
			for(int j = 0; j < other.card; j++){
				if(other.members[j] == this->members[i]){
					f = 1;
					break;
				}
			}
			if(f != 1){
				return false;
			}
		}
	}
	else{
		return false;
	}
	return true;
}


bool set::operator>=(const set &other) const{
	return (other <= *this);
}

void operator<<(std::ostream& ost, const set& A){
    for(int i = 0; i < A.card; i++) {
        ost << A.members[i] << " ";
    }
    return;
}

void operator>>(std::istream& ist, set &A){
	ist >> A.card;
	A.members = new int[A.card];
    for(int i = 0; i < A.card; i++) {
        ist >> A.members[i];
		for(int j = 0; j < i; j++){
			if(A.members[i] == A.members[j]){
				std::cout << "two members coincide";
				exit(-1);
			}
		}
    }
    return;
}
