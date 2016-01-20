#pragma once 
// #ifndef BoolVector_h
// #def BoolVector_h
// KOD!
// #endif 

class BoolVector
{
private:
	unsigned int x;
public:
	BoolVector();
	BoolVector(unsigned int);
	bool set(const int);
	bool clear(const int);
	int operator[](const int)const;
	~BoolVector();
	void print()const;

};
