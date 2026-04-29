#pragma once
#include <cstring>
#include <cstdio>
using namespace std;

struct Customer
{
	int id;
	char gender;
	char name[20];
	char priority;		// 'y':즉시 주선 희망, 'n' : 일반 대기	
public:
	Customer() : id(0), gender('m'), name{ '\0' }, priority('n') {}
	Customer(int id, char gen = 'm', const char* name = "", char pri = 'n') : id(id), gender(gen), priority(pri) {
		strcpy_s(this->name, sizeof(this->name), name);		// C 스타일 문자열 복사, 버퍼 오버플로우 방지
	}
	~Customer() {}
	const char* getName() const { return name; }
	char getGender() const { return gender; }
	char getPriority() const { return priority; }
	int getId() const { return id; }
};

