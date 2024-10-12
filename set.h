#ifndef SET_H
#define SET_H
#include <iostream>
class set{
	int c;
	int *m;
public:
	class Invalid {};
	set(int c, int *m);
	set();
	int cardio() const{ return c; }
	int *members() const {return m;}
	set(const set &A);
	~set();
	bool belonging(int z);
	set operator|(const set &A);
	set& operator=(const set &A);
	set& operator|=(const set &other);
	bool operator==(const set &A) const;
	bool operator<=(const set &other) const;
	bool operator>=(const set &other) const;
	friend void operator<<(std::ostream& ost, const set &A);
	friend void operator>>(std::istream& ist, set &A);
	void reset();
	
};

bool test();
bool is_set(int c, int *m);














#endif