#include <stdio.h>
#define MAX_NODE 100

typedef struct _node {		
	int x;
	int y;
	int value;
	_node* prev;
	_node* next;
} NODE;

struct _answer {
	int N;
	NODE node[MAX_NODE];	
};

_answer answer[24] =
{
	{1,{{1,1,0},}},
	{1,{{1,1,0},}},
	{2,{{1,1,0},{1,2,0},}},
	{2,{{1,2,0},{1,1,0},}},
	{3,{{1,1,0},{1,2,0},{2,2,0},}},
	{3,{{2,2,0},{1,2,0},{1,1,0},}},
	{3,{{1,1,0},{9,9,0},{2,2,0},}},
	{3,{{2,2,0},{9,9,0},{1,1,0},}},
	{4,{{1,1,0},{9,9,0},{4,1,0},{2,2,0},}},
	{4,{{2,2,0},{4,1,0},{9,9,0},{1,1,0},}},
	{3,{{2,2,0},{4,1,0},{9,9,0},}},
	{2,{{9,9,0},{4,1,0},}},
	{2,{{4,1,0},{9,9,0},}},
	{1,{{9,9,0},}},
	{1,{{9,9,0},}},
	{0,{{0,0,0},}},
	{0,{{0,0,0},}},
	{16,{{0,0,0},{0,0,1},{0,0,2},{0,0,3},{0,0,4},{0,0,5},{0,0,6},{0,0,7},{0,0,8},{0,0,9},{0,0,11},{0,0,13},{0,0,30},{0,0,50},{0,0,99},{0,0,100},}},
	{15,{{0,0,1},{0,0,2},{0,0,3},{0,0,4},{0,0,5},{0,0,6},{0,0,7},{0,0,8},{0,0,9},{0,0,11},{0,0,13},{0,0,30},{0,0,50},{0,0,99},{0,0,100},}},
	{14,{{0,0,1},{0,0,2},{0,0,3},{0,0,4},{0,0,5},{0,0,6},{0,0,7},{0,0,8},{0,0,9},{0,0,11},{0,0,13},{0,0,30},{0,0,50},{0,0,100},}},
	{14,{{0,0,1},{0,0,2},{0,0,3},{0,0,4},{0,0,5},{0,0,6},{0,0,7},{0,0,8},{0,0,9},{0,0,11},{0,0,13},{0,0,30},{0,0,50},{0,0,100},}},
	{14,{{0,0,1},{0,0,2},{0,0,3},{0,0,4},{0,0,5},{0,0,6},{0,0,7},{0,0,8},{0,0,9},{0,0,11},{0,0,13},{0,0,30},{0,0,50},{0,0,100},}},
	{13,{{0,0,2},{0,0,3},{0,0,4},{0,0,5},{0,0,6},{0,0,7},{0,0,8},{0,0,9},{0,0,11},{0,0,13},{0,0,30},{0,0,50},{0,0,100},}}
};

// 초기화
extern void Init(void);
// 좌표(x, y)를 넣어면 해당 Node 반환
extern NODE * Find(int x, int y);
// 특정 좌표에 대한 Node 삭제
extern void Remove(NODE * node);
// 중간에 삽입 - 주어진 Node 뒤에 좌표(x, y)값의 Node 삽입
extern NODE * Insert(NODE * node, int x, int y);
// List 맨 끝에 좌표(x, y)값의 Node 삽입
extern NODE * Push(int x, int y);
// 처음부터 리스트 출력
extern void Print(int *N, NODE list[]);
// 마지막부터 리스트 출력
extern void ReversalPrint(int * N, NODE list[]);
// 좌표(x, y)에 해당하는 Node 출력
extern void PrintNode(NODE * node, int *x, int *y);
// Single Linked List 관련 함수 (3개)
extern void AddSList(int value);
extern void DelSList(int value);
extern void PrintSList(int* N, NODE list[]);

void printlist(int N, NODE list[])
{
	printf("List(%d) { ", N);
	for (int i = 0; i < N; i++)
	{
		if (i != 0) printf(" > ");
		printf("(%d,%d,[%d])", list[i].x, list[i].y, list[i].value);
	}
	printf(" }\n");
}

int Check(int TC, int N, NODE solution[])
{
	printlist(N, solution);
	if (answer[TC].N == N)
	{
		for (int i = 0; i < N; i++)
		{
			if (answer[TC].node[i].x != solution[i].x ||
				answer[TC].node[i].y != solution[i].y || 
				answer[TC].node[i].value != solution[i].value)
				return 0;
		}
		return 1;
	}
	return 0;
}

int main(void)
{

	NODE *Node1, *Node2, *Node3, *Node4;
	NODE *FoundNode1, *FoundNode2;
	NODE result[MAX_NODE];
	int x = 0;
	int	y = 0;
	int N = 0;
	int score = 0;
	int T = 0;

	printf("#Linked list TC start!!!\n");
	Init();

	Node1 = Push(1, 1);
	Print(&N, result);			// ▶  (1, 1)
	score += Check(T++, N, result);	// CHECK#01
	ReversalPrint(&N, result);		// ▶  (1, 1)
	score += Check(T++, N, result);	// CHECK#02
	Node2 = Push(1, 2);
	Print(&N, result);			// ▶  (1, 1), (1, 2)
	score += Check(T++, N, result);	// CHECK#03
	ReversalPrint(&N, result);		// ▶  (1, 2), (1, 1)
	score += Check(T++, N, result);	// CHECK#04
	Node3 = Push(2, 2);
	Print(&N, result);			// ▶  (1, 1), (1, 2), (2, 2)
	score += Check(T++, N, result);	// CHECK#05
	ReversalPrint(&N, result);		// ▶  (2, 2), (1, 2), (1, 1)
	score += Check(T++, N, result);	// CHECK#06
	FoundNode2 = Find(1, 2);
	x = 0, y = 0;
	PrintNode(FoundNode2, &x, &y);	// ▶  (1, 2)
	if (x == 1 && y == 2) score++;
	if (FoundNode2 != NULL)
	{
		FoundNode2->x = 9;
		FoundNode2->y = 9;
	}
	FoundNode2 = Find(9, 9);
	x = 0, y = 0;
	PrintNode(FoundNode2, &x, &y);		// ▶  (9, 9)
	if (x == 9 && y == 9) score++;
	Print(&N, result);			// ▶  (1, 1), (9, 9), (2, 2)
	score += Check(T++, N, result);	// CHECK#07
	ReversalPrint(&N, result);		// ▶  (2, 2), (9, 9), (1, 1)
	score += Check(T++, N, result);	// CHECK#08
	Node4 = Insert(Node2, 4, 1);
	Print(&N, result);			// ▶  (1, 1), (9, 9), (4, 1), (2, 2);
	score += Check(T++, N, result);	// CHECK#09
	ReversalPrint(&N, result);		// ▶  (2, 2), (4, 1), (9, 9), (1, 1);
	score += Check(T++, N, result);	// CHECK#10
	Remove(Node1);
	ReversalPrint(&N, result);		// ▶  (2, 2), (4, 1), (9, 9)
	score += Check(T++, N, result);	// CHECK#11
	Remove(Node3);
	Print(&N, result);			// ▶  (9, 9), (4, 1)
	score += Check(T++, N, result);	// CHECK#12
	ReversalPrint(&N, result);		// ▶  (4, 1), (9, 9)
	score += Check(T++, N, result);	// CHECK#13
	Remove(Node4);
	Print(&N, result);			// ▶  (9, 9)
	score += Check(T++, N, result);	// CHECK#14
	ReversalPrint(&N, result);		// ▶  (9, 9)
	score += Check(T++, N, result);	// CHECK#15
	Remove(FoundNode2);
	N = -1;
	Print(&N, result);	
	score += Check(T++, N, result);	// CHECK#16
	N = -1;
	ReversalPrint(&N, result);
	score += Check(T++, N, result);	// CHECK#17
	Init();

	AddSList(9);
	AddSList(2);
	AddSList(6);
	AddSList(0);
	AddSList(1);
	AddSList(5);
	AddSList(3);
	AddSList(4);
	AddSList(7);
	AddSList(8);
	AddSList(11);
	AddSList(100);
	AddSList(13);
	AddSList(99);
	AddSList(50);
	AddSList(30);
	PrintSList(&N, result);
	score += Check(T++, N, result);	// CHECK#18
	DelSList(0);
	PrintSList(&N, result);
	score += Check(T++, N, result);	// CHECK#19
	DelSList(99);
	PrintSList(&N, result);
	score += Check(T++, N, result);	// CHECK#21
	DelSList(99);
	PrintSList(&N, result);
	score += Check(T++, N, result);	// CHECK#22
	DelSList(0);
	PrintSList(&N, result);
	score += Check(T++, N, result);	// CHECK#23
	DelSList(1);
	PrintSList(&N, result);
	score += Check(T++, N, result);	// CHECK#24

	printf("#Linked list TC : { score : %d/25, %s}", score, (score == 25) ? "PASS" : "FAILE");

	return 1;
}

