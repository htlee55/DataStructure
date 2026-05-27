// Record.h: 사전을 위한 레코드 클래스
#include <cstdio>
#include <cstring>
#define MAX_WORD_SIZE		40
#define MAX_MEANING_SIZE	200

class Record
{
protected:
	char	word[MAX_WORD_SIZE];		// 단어: 키 필드
	char	meaning[MAX_MEANING_SIZE];	// 의미
public:
	Record(const char* w = "", const char* m = "") { set(w, m); }
	void set(const char* w, const char* m) {
		strcpy_s(word, w);
		strcpy_s(meaning, m);
	}
	int compare(Record* n) { return compare(n->word); }
	int compare(char* w) { return strcmp(w, word); }
	int compareMeaning(char* m) { return strcmp(meaning, m); }
	void display() { printf(" %12s : %-40s\n", word, meaning); }
	void copy(Record* n) { set(n->word, n->meaning); }
};
