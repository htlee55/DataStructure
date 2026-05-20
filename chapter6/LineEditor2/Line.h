#pragma once

#include <stdio.h>
#include <string.h>
#define MAX_CHAR_PER_LINE	1000

class Line
{
	char data[MAX_CHAR_PER_LINE];
public:
	Line(const char* line = "") { strcpy_s(data, line); }

	void read(FILE* fp = stdin) { fgets(data, MAX_CHAR_PER_LINE, fp); }

	void display(FILE* fp = stdout) { fprintf(fp, "%s", data); }

	bool hasData(char* str) { return strcmp(str, data) == 0; }
};
