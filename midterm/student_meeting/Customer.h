#pragma once
#include <cstring>
struct Customer
{
	int id;
	char gender;
	char name[20];
	char priority;
public:
	Customer() : id(0), gender('m'), name{ '\0' }, priority('n') {}
	Customer(int id, char gen = 'm', const char* name = "", char pri = 'n') : id(id), gender(gen), priority(pri) {
		strcpy_s(this->name, sizeof(this->name), name);	// C-style string copy, buffer overflow prevented
	}
	~Customer() { }
	const char* getName() const { return name; }
	char getGender() const { return gender; }
	char getPriority() const { return priority; }
	int getId() const { return id; }
};

