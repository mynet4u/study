#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define nullptr 0L

typedef struct _NODE {
	int x;
	int y;
	struct _NODE * prev;
	struct _NODE * next;
} NODE;

void Init(void);
// 좌표(x, y)를 넣어면 해당 Node 반환
NODE * Find(int x, int y);
// 특정 좌표에 대한 Node 삭제
void Remove(NODE * node);
// 중간에 삽입 - 주어진 Node 뒤에 좌표(x, y)값의 Node 삽입
NODE * Insert(NODE * node, int x, int y);
// List 맨 끝에 좌표(x, y)값의 Node 삽입
NODE * Push(int x, int y);
// 처음부터 리스트 출력
void Print(void);
// 마지막부터 리스트 출력
void ReversalPrint(void);
// 좌표(x, y)에 해당하는 Node 출력
void PrintNode(NODE * node);

int main(void)
{
	NODE *Node1, *Node2, *Node3, *Node4;
	NODE *FoundNode1, *FoundNode2;

	Node1 = Push(1, 1);
	Print();								// ▶  (1, 1);
	ReversalPrint();					// ▶  (1, 1);
	Node2 = Push(1, 2);
	Print();								// ▶  (1, 1);, (1, 2);
	ReversalPrint();					// ▶  (1, 2);, (1, 1);
	Node3 = Push(2, 2);
	Print();								// ▶  (1, 1);, (1, 2);, (2, 2);
	ReversalPrint();					// ▶  (2, 2);, (1, 2);, (1, 1);
	FoundNode2 = Find(1, 2);
	PrintNode(FoundNode2);		// ▶  (1, 2);
	FoundNode2->x = 9;
	FoundNode2->y = 9;
	FoundNode2 = Find(9, 9);
	PrintNode(FoundNode2);		// ▶  (9, 9);
	Print();								// ▶  (1, 1);, (9, 9);, (2, 2);
	ReversalPrint();					// ▶  (2, 2);, (9, 9);, (1, 1);
	Node4 = Insert(Node2, 4, 1);
	Print();								// ▶  (1, 1);, (9, 9);, (4, 1);, (2, 2);
	ReversalPrint();					// ▶  (2, 2);, (4, 1);, (9, 9);, (1, 1);
	Remove(Node1);
	Print();								// ▶  (9, 9);, (4, 1);, (2, 2);
	ReversalPrint();					// ▶  (2, 2);, (4, 1);, (9, 9);
	Remove(Node3);
	Print();								// ▶  (9, 9);, (4, 1);
	ReversalPrint();					// ▶  (4, 1);, (9, 9);
	Remove(Node4);
	Print();								// ▶  (9, 9);
	ReversalPrint();					// ▶  (9, 9);
	Remove(FoundNode2);
	Print();
	ReversalPrint();

	return 1;
}
