
#if 0
#define DEBUG
#ifndef DEBUG
#define PRINT
#else
#include <stdio.h>
#define PRINT printf
#endif

#define MAX_NODE 1000
#define MAX_RESULT_SIZE 500
#define MAX_STRING_SIZE 20
#define ALPHABET_NUM 26
#define nullptr 0L

typedef struct _node {
	int isWord;
	char ch;
	_node * next;
	_node * children;
} NODE;
NODE root;
NODE arr[MAX_NODE];
int arr_index;
NODE * nodeAlloc() {
	arr[arr_index].isWord = 0;
	arr[arr_index].next = arr[arr_index].children = nullptr;
	return &arr[arr_index++];
}

int _strlen(const char *str)
{
	int cnt = 0;
	while (str[cnt] != '\0')
	{
		cnt++;
	}
	return cnt;
}

int _strcpy(const char *src, char *dst)
{
	int cnt = 0;
	while (src[cnt] != '\0')
	{
		dst[cnt] = src[cnt];
		cnt++;
	}
	dst[cnt] = '\0';
	return cnt;
}


void init()
{
	arr_index = 0;
	root.isWord = 0;
	root.ch = 0;
	root.next = root.children = nullptr;

}

NODE * findChildren(NODE * p, char ch)
{
	while (p != nullptr)
	{
		if (ch == p->ch) return p;
		p = p->next;
	}
	return nullptr;
}

NODE * addChild(NODE **pp, NODE * p, char ch)
{

	NODE * pNew = nodeAlloc();
	pNew->ch = ch;

	while (p != nullptr)
	{
		if (p->ch > ch) break;
		pp = &p->next;
		p = p->next;
	}
	pNew->next = p;

	*pp = pNew;


	return pNew;
}

void add(char str[])
{
	int len = _strlen(str);
	if (len > 0)
	{
		NODE * parent = &root;
		for (int i = 0; i < len; i++)
		{
			NODE * child = findChildren(parent->children, str[i]);
			if (child == nullptr)
			{
				child = addChild(&parent->children, parent->children, str[i]);
			}
			parent = child;
		}
		parent->isWord = 1;
	}
}
int find(char str[])
{
	PRINT("find(%s)[", str);
	int len = _strlen(str);
	int result = 0;
	if (len > 0)
	{
		NODE * parent = &root;
		int i = 0;
		while (i < len)
		{
			NODE * child = findChildren(parent->children, str[i]);
			if (child == nullptr) break;
			PRINT("%c", child->ch);
			parent = child;
			i++;
		}
		if (len == i && parent->isWord == 1) result = 1;
	}
	PRINT("](result:%d)\n", result);
	return result;
}

void findlist(NODE * root, int depth, char string[], char res[][MAX_STRING_SIZE], int &resIdx)
{
	if (root->isWord == 1)
	{
		string[depth] = '\0';
		_strcpy(string, res[resIdx]);
		PRINT("\tres[%d] : { %s }\n", resIdx, res[resIdx]);
		resIdx++;

		if (root->children == nullptr) return;
	}

	for (NODE * p = root->children; p != nullptr; p = p->next)
	{
		string[depth] = p->ch;
		findlist(p, depth + 1, string, res, resIdx);
	}
}

void list(char res[][MAX_STRING_SIZE], int &resIdx)
{
	char string[MAX_STRING_SIZE];
	findlist(&root, 0, string, res, resIdx);
}
#endif
