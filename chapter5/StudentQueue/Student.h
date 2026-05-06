#pragma once
#include <stdio.h>
#include <string.h>
#define MAX_STRING	100

class Student
{
	int		id;					
	char	name[MAX_STRING];	
	char	dept[MAX_STRING];	
public:
	Student(int i=0, const char* nam="", const char* dep="") { 
		set( i, nam, dep );
	}
	void set(int i, const char* nam, const char* dep) {
		id = i;
		strcpy_s( name, nam );
		strcpy_s( dept, dep );
	}
	void display() {
		printf(" 학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
	}
};
