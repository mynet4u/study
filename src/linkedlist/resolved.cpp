#if 0
//1005 01:05
#define MAX_NODE 10000
#define nullptr 0L

typedef struct _node {
	int x;
	int y;
	int value;
} NODE;

typedef struct _list {
	NODE node;
	_list* prev;
	_list* next;
} LIST;
int arr_index;
LIST arr[MAX_NODE];
LIST* myalloc() { return &arr[arr_index++]; }
LIST HEAD, TAIL;
LIST* head = &HEAD;
LIST* tail = &TAIL;

void Init(void)
{
	arr_index = 0;
	head->next = tail;
	tail->prev = head;
}

NODE* Find(int x, int y)
{
	for (LIST* p = head->next; p != tail; p = p->next)
	{
		if (p->node.x == x && p->node.y == y) return &p->node;
	}
	return nullptr;
}

LIST* findList(NODE* node)
{
	if (node != nullptr)
	{
		for (LIST* p = head->next; p != tail; p = p->next)
		{
			if (node == &p->node) {
				return p;
			}
		}
	}
	return nullptr;
}

void Remove(NODE* node)
{
	LIST* list = findList(node);
	if (list != nullptr)
	{
		list->prev->next = list->next;
		list->next->prev = list->prev;
		list->prev = list->next = nullptr;
	}
}

NODE* Insert(NODE* node, int x, int y)
{
	LIST* list = findList(node);
	if (list != nullptr)
	{
		LIST* pNew = myalloc();
		pNew->node.x = x;
		pNew->node.y = y;
		pNew->node.value = 0;
		pNew->prev = list;
		pNew->next = list->next;
		list->next->prev = pNew;
		list->next = pNew;

		return &pNew->node;
	}
	return nullptr;
}

NODE* Push(int x, int y)
{
	LIST* pNew = myalloc();
	pNew->node.x = x;
	pNew->node.y = y;
	pNew->node.value = 0;
	pNew->prev = tail->prev;
	pNew->next = tail;
	tail->prev->next = pNew;
	tail->prev = pNew;

	return &pNew->node;
}

void Print(int* N, NODE list[])
{
	int cnt = 0;
	for (LIST* p = head->next; p != tail; p = p->next)
	{
		list[cnt].x = p->node.x;
		list[cnt].y = p->node.y;
		list[cnt].value = 0;
		cnt++;
	}
	*N = cnt;
}

void ReversalPrint(int* N, NODE list[])
{
	int cnt = 0;
	for (LIST* p = tail->prev; p != head; p = p->prev)
	{
		list[cnt].x = p->node.x;
		list[cnt].y = p->node.y;
		list[cnt].value = 0;
		cnt++;
	}
	*N = cnt;
}

void PrintNode(NODE* node, int* x, int* y)
{
	*x = node->x;
	*y = node->y;
}

void AddSList(int value)
{
	LIST* pNew = myalloc();
	LIST* p = head->next;
	LIST** pp = &head->next;
	while (p != tail)
	{
		if (p->node.value > value) break;
		pp = &p->next;
		p = p->next;
	}
	pNew->node.x = 0;
	pNew->node.y = 0;
	pNew->node.value = value;
	pNew->next = p;
	*pp = pNew;
}

void DelSList(int value)
{
	LIST* p = head->next;
	LIST** pp = &head->next;
	while (p != tail)
	{
		if (p->node.value == value)
		{
			*pp = p->next;
			p->next = nullptr;
			return;
		}
		pp = &p->next;
		p = p->next;
	}
}

void PrintSList(int* N, NODE list[])
{
	int cnt = 0;
	for (LIST* p = head->next; p != tail; p = p->next)
	{
		list[cnt].x = 0;
		list[cnt].y = 0;
		list[cnt].value = p->node.value;
		cnt++;
	}
	*N = cnt;
}
/*
#define DEBUG
#ifndef DEBUG
#define PRINT
#else
#include <stdio.h>
#define PRINT printf
#endif // !DEBUG

#define MAX_NODE 50000
#define nullptr 0L

typedef struct _node {
	int value;
	int x;
	int y;
	_node* prev;
	_node* next;
} NODE;
NODE arr[MAX_NODE];
NODE head, tail;
int arr_index;
NODE* nodeAlloc() { return &arr[arr_index++]; }

void Init(void)
{
	arr_index = 0;
	head.next = &tail;
	tail.prev = &head;
}

NODE* Find(int x, int y)
{
	for (NODE* p = head.next; p != &tail; p = p->next)
	{
		if (p->x == x && p->y == y) return p;
	}
	return nullptr;
}

void Remove(NODE* node)
{
	if (node != nullptr)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		node->prev = node->next = nullptr;
	}
}

NODE* Insert(NODE* node, int x, int y)
{
	if (node == nullptr) return nullptr;
	NODE* pNew = nodeAlloc();
	pNew->x = x;
	pNew->y = y;
	pNew->prev = node;
	pNew->next = node->next;
	node->next->prev = pNew;
	node->next = pNew;

	return pNew;
}

NODE* Push(int x, int y)
{
	NODE* pNew = nodeAlloc();
	pNew->x = x;
	pNew->y = y;
	pNew->prev = tail.prev;
	pNew->next = &tail;
	tail.prev->next = pNew;
	tail.prev = pNew;

	return pNew;
}

void Print(void)
{
	PRINT("Dll(>) { ");
	for (NODE* p = head.next; p != &tail; p = p->next)
	{
		if (p != head.next) PRINT(" > ");
		PRINT("(%d,%d)", p->x, p->y);
	}
	PRINT(" }\n");
}

void ReversalPrint(void)
{
	PRINT("Dll(<) { ");
	for (NODE* p = tail.prev; p != &head; p = p->prev)
	{
		if (p != tail.prev) PRINT(" < ");
		PRINT("(%d,%d)", p->x, p->y);
	}
	PRINT(" }\n");
}

void PrintNode(NODE* node)
{
	PRINT("NODE : ");
	if (node != nullptr)
		PRINT("(%d,%d)", node->x, node->y);
	PRINT(".\n");
}

void PrintSList();
void AddSList(int value)
{
	NODE* pNew = nodeAlloc();
	pNew->value = value;
	NODE* p = head.next;
	NODE* pp = &head;
	while (p != &tail)
	{
		if (p->value > value) break;
		pp = p;
		p = p->next;
	}
	pNew->next = p;
	pp->next = pNew;
	PrintSList();
}

void DelSList(int value)
{
	NODE* p = head.next;
	NODE* pp = &head;
	while (p != &tail)
	{
		if (p->value == value)
		{
			pp->next = p->next;
			p->next = nullptr;
			PrintSList();
			return;
		}
		pp = p;
		p = p->next;
	}
	return;
}

void PrintSList()
{
	PRINT("Sll { ");
	for (NODE* p = head.next; p != &tail; p = p->next)
	{
		if (p != head.next) PRINT(", ");
		PRINT("%d", p->value);
	}
	PRINT(" }\n");
}
*/
#endif
