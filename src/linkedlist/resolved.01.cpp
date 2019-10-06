#if 1
// 11:27 -> 11:52 (25)
#define MAX_NODE	100000
#define nullptr		0L
typedef struct _node {
	int x;
	int y;
	int value;
	_node* prev;
	_node* next;
} NODE;
int arr_index;
NODE arr[MAX_NODE], head, tail;
NODE* myalloc() { return &arr[arr_index++]; }

void Init(void)
{
	arr_index = 0;
	head.next = &tail;
	tail.prev = &head;
}

NODE* Find(int x, int y)
{
	NODE* p = head.next;
	while (p != nullptr)
	{
		if (p->x == x && p->y == y) 
			break;
		p = p->next;
	}
	return p;
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
	NODE* pNew = myalloc();
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
	NODE* pNew = myalloc();
	pNew->x = x;
	pNew->y = y;
	pNew->prev = tail.prev;
	pNew->next = &tail;
	tail.prev->next = pNew;
	tail.prev = pNew;

	return pNew;
}

void Print(int* N, NODE list[])
{
	int cnt = 0;
	for (NODE* p = head.next; p != &tail; p = p->next)
	{
		list[cnt].x = p->x;
		list[cnt].y = p->y;
		list[cnt].value = 0;
		cnt++;
	}
	*N = cnt;
}

void ReversalPrint(int* N, NODE list[])
{
	int cnt = 0;
	for (NODE* p = tail.prev; p != &head; p = p->prev)
	{
		list[cnt].x = p->x;
		list[cnt].y = p->y;
		list[cnt].value = 0;
		cnt++;
	}
	*N = cnt;
}

void PrintNode(NODE* node, int* x, int* y)
{
	if (node != nullptr)
	{
		x = &node->x;
		y = &node->y;
	}
}

void AddSList(int value)
{
	NODE* pNew = myalloc();
	NODE* p = head.next;
	NODE** pp = &head.next;
	while (p != &tail)
	{
		if (p->value > value) break;
		pp = &p->next;
		p = p->next;
	}
	pNew->value = value;
	pNew->next = p;
	*pp = pNew;
}

void DelSList(int value)
{
	NODE* p = head.next;
	NODE** pp = &head.next;
	while (p != &tail)
	{
		if (p->value == value)
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
	for (NODE* p = head.next; p != &tail; p = p->next)
	{
		list[cnt].x = 0;
		list[cnt].y = 0;
		list[cnt].value = p->value;
		cnt++;
	}
	*N = cnt;
}
#endif
