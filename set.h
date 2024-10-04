#include <iostream>
class set{
	//cardinality of the set
	int card;
	int *members;
public:
	//empty constructor
	set();
	//copy constructor
	set(const set &A);
	//destructor
	~set();
	//test on belonging member z to set A
	bool belonging(const set &A, int z);
	set operator|(const set &A);
	set& operator=(const set &A);
	set& operator|=(const set &other);
	bool operator==(const set &A) const;
	bool operator<=(const set &other) const;
	bool operator>=(const set &other) const;
	friend void operator<<(std::ostream& ost, const set &A);
	friend void operator>>(std::istream& ist, set &A);
	bool test_set();
};