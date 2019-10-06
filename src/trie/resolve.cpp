#if 0
#define DEBUG
#ifndef DEBUG
#define PRINT
#else
#include <stdio.h>
#define PRINT printf
#endif
#define MAX_RESULT_SIZE 500
#define MAX_STRING_SIZE 20
#define MAX_NODE		10000
#define ALPHBAT			26
#define nullptr			0L

typedef struct _node {
	//char a;
	bool isWorld;
	_node* children[ALPHBAT];	
} NODE;
int arr_index;
NODE arr[MAX_NODE], root;
NODE* myalloc() {
	arr[arr_index].isWorld = false;
	for (int i = 0; i < ALPHBAT; i++)
	{		
		arr[arr_index].children[i] = nullptr;
	}
	return &arr[arr_index++];
}
void init()
{
	arr_index = 0;
	root.isWorld = false;
	for (int i = 0; i < ALPHBAT; i++)
	{		
		root.children[i] = nullptr;
	}
}
void add(char str[])
{
	PRINT("%s\n", str);
	NODE* p = &root;
	for (int i = 0; str[i] != '\0'; i++)
	{
		int index = str[i] - 'a';
		if (p->children[index] == nullptr)
		{
			p->children[index] = myalloc();
		}		
		p = p->children[index];
	}
	p->isWorld = true;
}
int find(char str[])
{
	NODE* p = &root;
	for (int i = 0; str[i] != '\0'; i++)
	{
		int index = str[i] - 'a';
		if (p->children[index] == nullptr)
		{
			return 0;
		}
		p = p->children[index];
	}
	if (p->isWorld == true)
		return 1;
	else
		return 0;
}

void _strcpy(const char src[], char dst[])
{
	int cnt = 0;
	while (src[cnt] != '\0')
	{
		dst[cnt] = src[cnt];
		cnt++;
	}
	dst[cnt] = '\0';
}

void listfind(NODE* node, int depth, char str[], char res[][MAX_STRING_SIZE], int& resIdx)
{
	if (node->isWorld)
	{
		_strcpy(str, res[resIdx]);		
		resIdx++;
		PRINT("\t\t[%2d] %s\n", resIdx, str);
	}

	for (int i = 0; i < ALPHBAT; i++)
	{
		if (node->children[i] != nullptr) {
			str[depth] = i + 'a';
			str[depth + 1] = 0;
			listfind(node->children[i], depth + 1, str, res, resIdx);
		}
			
	}
}

void list(char res[][MAX_STRING_SIZE], int& resIdx)
{
	char string[MAX_STRING_SIZE];
	listfind(&root, 0, string, res, resIdx);
}
#endif
