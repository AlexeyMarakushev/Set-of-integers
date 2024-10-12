#include "set.h"
#include <iostream>

set::set(int cc, int *mm)
	: c{cc}, m{mm}
	{
		if(!is_set(cc, mm)) throw Invalid{};
	}

set::set(){
    c = 0;
    m = nullptr;
}

set::~set() {
    delete[] m;
}

set::set(const set &A){
    c = A.c;
    m = new int[c];
    for(int i = 0; i < c; i++) {
        m[i] = A.m[i]; 
    }
}

set& set::operator=(const set &A){
    if(this != &A) {
        if(m != nullptr){
            delete[] m;
        }
        c = A.c;
        m = new int[c];
        for (int i = 0; i < c; i++) {
            m[i] = A.m[i]; 
        }
    }
    return *this;
}

set set::operator|(const set &A){
	set C;
	int i, j, f, k = 0, q = this->c + A.c;
	for(i = 0; i < this->c; i++){
		for(j = 0; j < A.c; j++){
			if(this->m[i] == A.m[j]){
				q--;
				break;
			}
		}
	}
	C.c = q;
	C.m = new int[C.c];
	for(i = 0; i < A.c; i++){
		C.m[i] = A.m[i];
	}
	for(i = 0; i < this->c; i++){
		f = 0;
		for(j = 0; j < A.c; j++){
			if(this->m[i] == A.m[j]){
				f = 1;
				break;
			}
		}
		if(f == 0){
			C.m[k + A.c] = this->m[i];
			k++;
		}
	}
	return C;
}

set& set::operator|=(const set &other){
	*this = *this | other;
	return *this;
}
bool set::belonging(int z){
	for(int i = 0; i < c; i++){
		if(z == m[i]){
			return true;
		}
	}
	return false;
}

bool set::operator==(const set &A) const{
	int f;
	if(this->c == A.c){
		for(int i = 0; i < A.c; i++){
			f = 0;
			for(int j = 0; j < this->c; j++){
				if(A.m[i] == this->m[j]){
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
	if(this->c <= other.c){
		for(int i = 0; i < this->c; i++){
			f = 0;
			for(int j = 0; j < other.c; j++){
				if(other.m[j] == this->m[i]){
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
    for(int i = 0; i < A.c; i++) {
        ost << A.m[i] << " ";
    }
    return;
}

void operator>>(std::istream& ist, set &A){
	ist >> A.c;
	A.m = new int[A.c];
    for(int i = 0; i < A.c; i++) {
        ist >> A.m[i];
		for(int j = 0; j < i; j++){
			if(A.m[i] == A.m[j]){
				std::cout << "two members coincide";
				exit(-1);
			}
		}
    }
    return;
}



bool is_set(int c, int *m){
	if(m == nullptr){
		std::cout << "the set is void";
		return false;
	}
	for(int i = 0; i < c; i++) {
		for(int j = 0; j < i; j++){
			if(m[i] == m[j]){
				std::cout << "two members coincide";
				return false;
			}
		}
	}
	return true;
}

void set::reset() {
    c = 0;
	if(m != nullptr) {
        delete[] m;
        m = nullptr;
    }
}