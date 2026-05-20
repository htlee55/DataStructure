#pragma once
//#define _CRT_SECURE_NO_WARNINGS
#include "LinkedList.h"
class LineEditor : public LinkedList
{
public:
	void Display(FILE* fp = stdout) {
		int i = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink(), i++) {	// 행 번호 출력, 화면 출력
			fprintf(stderr, "%3d: ", i);			// 행 번호 출력, 파일 출력
			p->display(fp);							// 행 번호 출력, 화면 출력
		}
	}

	void InsertLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		printf("  입력행 번호: ");
		scanf_s("%d", &position);			// 행 번호 입력
		printf("  입력행 내용: ");
		while (getchar() != '\n');	// 입력 버퍼 비우기, 다음 입력을 위해
		fgets(line, MAX_CHAR_PER_LINE, stdin);		// 행 내용 입력, 화면 입력, 파일 입력

		insert(position, new Node(line));
	}
	void DeleteLine() {
		printf("  삭제행 번호: ");
		int position;
		scanf_s("%d", &position);

		remove(position);
	}
	void ReplaceLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		printf("  변경행 번호: ");
		scanf_s("%d", &position);
		printf("  변경행 내용: ");
		while (getchar() != '\n');	// 입력 버퍼 비우기, 다음 입력을 위해
		fgets(line, MAX_CHAR_PER_LINE, stdin);

		replace(position, new Node(line));
	}

	void LoadFile(const char* fname) {
		FILE* fp = nullptr;
		if (fopen_s(&fp, fname, "r") == 0) {
			char line[MAX_CHAR_PER_LINE];
			while (fgets(line, MAX_CHAR_PER_LINE, fp))
				insert(size(), new Node(line));
			fclose(fp);
		}
	}
	void StoreFile(const char* fname) {
		FILE* fp = nullptr;
		if (fopen_s(&fp, fname, "w") == 0) {
			Display(fp);
			fclose(fp);
		}
	}
	void Search(){
		char line[MAX_CHAR_PER_LINE];
		printf("  검색행 내용: ");
		while (getchar() != '\n');	// 입력 버퍼 비우기, 다음 입력을 위해
		fgets(line, MAX_CHAR_PER_LINE, stdin);
		Node* found = find(line);
		if (found != NULL) {
			printf("  검색 결과: ");
			found->display();
		}
		else
			printf("  검색 결과: 없음\n");
	}
};


